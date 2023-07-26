/* 各ヘッダのインクルード */
#include <stdio.h>  // 各入出力で使用
#include <stdlib.h> // 動的メモリ管理、exit関数で使用

#define GNUPLOT "gnuplot -persist"

/* ペア型の定義 */
typedef struct Pair {
  float n;
  float m;
  struct Pair* nextPt;
} Pair;

/* 単精度浮動点小数要素の定義 */
typedef struct Float {
  float n;
  struct Float* nextPt;
} Float;

/* 行列型の定義 */
typedef struct Matrix {
  float a;
  float b;
  float c;
  float d;
} Matrix;

/* ベクトル型の定義 */
typedef struct Vector {
  float a;
  float b;
} Vector;


/* 各関数のプロトタイプ宣言 */
Pair* loadCSV(char* filename);
void splitToFloat(Pair* p, Float** f1, Float** f2);
float solveSigma(Float* f1, Float* f2);
int countFloat(Float* f);
Pair findRange(Float* f);
Matrix solveMatrixInverse(Matrix m);
Vector solveDotProduct(Vector v, Matrix m);
void freePair(Pair* p);
void freeFloat(Float* f);
float linerEquation(float x, Vector v);
float linerEquationInverse(float y, Vector v);
void plot(Float* x, Float* y, Vector v);
float solveRMSE(Float* x, Float* y, Vector v);
float solvePow(float f);
float solveSqrt(float x);


/* メイン関数 */
int main(int argc, char *argv[]) {
  // コマンドライン引数が合っているか判定
  if (argc != 2) {
	 printf("IllegalArgumentsError\n");
	 printf("usage: ./LeastSquaresMethod <filename>\n");
	 return -1;
  }
  // CSVファイルからデータをロード
  Pair* points = loadCSV(argv[1]);

  // 各座標の空のリストを宣言 
  Float *X = NULL;
  Float *Y = NULL;

  // 座標からX,Yのそれぞれのデータを抽出
  splitToFloat(points, &X, &Y);

  // 抽出してきたデータからそれぞれの行列・ベクトルを求める
  Matrix A = {solveSigma(X, X), solveSigma(X, NULL)
				  ,solveSigma(X, NULL), countFloat(X)};
  Vector B = {solveSigma(X, Y)
  				  ,solveSigma(Y, NULL)};

  // 演算のためにA行列の逆行列を求める
  Matrix AInv = solveMatrixInverse(A);

  // それぞれの行列とベクトルから答えを求める
  Vector ans = solveDotProduct(B, AInv);

  // 結果の表示
  printf("(%f %f)\n", ans.a, ans.b);
  printf("RMSE=%f\n", solveRMSE(X, Y, ans));
  printf("(1) xが2050の時のyの値を推定せよ\nAns=%f\n", linerEquation(2050, ans));
  printf("(2) yが9.0になるxを推定せよ\nAns=%f\n", linerEquationInverse(9, ans));
  
  // グラフの表示
  plot(X, Y, ans);
  
  // 各リストのメモリ解放
  freePair(points);
  freeFloat(X);
  freeFloat(Y);
  return 0;
}

float solveSqrt(float x) {
  float y, z, result;
  if (x == 0) {
	 return 0;
  } else {
	 y = 1;
	 for (int i = 0; i <= 10; i++) {
		z = x / y;
		result = (y + z) / 2;
		y = result;
	 }
	 return result;
  }
}

float solvePow(float f) {
  return f * f;
}

float solveRMSE(Float* x, Float* y, Vector v) {
  float rmse = 0;
  Float* currentX = x;
  Float* currentY = y;
  while (currentX != NULL || currentY != NULL) {
	 rmse += solvePow((linerEquation(currentX -> n, v) - currentY -> n));
	 currentX = currentX -> nextPt;
	 currentY = currentY -> nextPt;
  }
  rmse /= countFloat(x);
  rmse = solveSqrt(rmse);
  return rmse;
}

/**
	FunctionName: plot
	
	Argument    : x, y, v
	ArgumentType: ListOfFloat, ListOfFloat, Vector
	
	Return      : void
	ReturnType  : void
	
	Description : 直線と点をプロットする関数
 */
void plot(Float* x, Float* y, Vector v) {
  FILE *gp;
  Float* currentX = x;
  Float* currentY = y;
  Pair rangeX = findRange(x);
  Pair rangeY = findRange(y);
  gp = popen(GNUPLOT, "w");
  if (gp == NULL) {
	 printf("FileOpenError \"%s\"\n", GNUPLOT);
	 exit(-1);
  }
  fprintf(gp, "set multiplot\n");
  fprintf(gp, "set xrange [%f:%f]\n", rangeX.n - 1, rangeX.m + 1);
  fprintf(gp, "set yrange [%f:%f]\n", rangeY.n - 1, rangeY.m + 1);
  fprintf(gp, "set xlabel \"x\"\n");
  fprintf(gp, "set ylabel \"x\"\n");

  fprintf(gp, "plot '-' with points pointtype 1\n");
  while (currentX != NULL || currentY != NULL) {
	 fprintf(gp, "%f\t%f\n", currentX -> n, currentY -> n);
	 currentX = currentX -> nextPt;
	 currentY = currentY -> nextPt;
  }
  fprintf(gp, "e\n");

  fprintf(gp, "plot '-' with lines linetype 1\n");
  currentX = x;
  while (currentX != NULL) {
	 fprintf(gp, "%f\t%f\n", currentX -> n, linerEquation(currentX -> n, v));
	 currentX = currentX -> nextPt;
  }
  fprintf(gp, "e\n");

  fprintf(gp, "set nomultiplot\n");
  fprintf(gp, "exit\n");
  fflush(gp);
  pclose(gp);
}

/**
	FunctionName: linerEquation
	
	Argument    : x, v
	ArgumentType: float, Vector
	
	Return      : y
	ReturnType  : float
	
	Description : xの値を代入するとyの値が返される直線方程式
 */
float linerEquation(float x, Vector v) {
  float y = v.a * x + v.b;
  return y;
}

float linerEquationInverse(float y, Vector v) {
  float x = (y - v.b) / v.a;
  return x;
}

/**
	FunctionName: freePair
	
	Argument    : f
	ArgumentType: ListOfPair
	
	Return      : void
	ReturnType  : void
	
	Description : Pairリストを全てメモリ解放する関数
 */
void freePair(Pair* p) {
  Pair *currentPair, *nextPair;
  currentPair = p;
  while (currentPair != NULL) {
	 nextPair = currentPair -> nextPt;
	 free(currentPair);
	 currentPair = nextPair;
  }
}

/**
	FunctionName: freeFloat
	
	Argument    : f
	ArgumentType: ListOfFloat
	
	Return      : void
	ReturnType  : void
	
	Description : Floatリストを全てメモリ解放する関数
 */
void freeFloat(Float* f) {
  Float *currentFloat, *nextFloat;
  while (currentFloat != NULL) {
	 nextFloat = currentFloat -> nextPt;
	 free(currentFloat);
	 currentFloat = nextFloat;
  }
}

/**
	FunctionName: solveDotProduct
	
	Argument    : v, m
	ArgumentType: Vector, Matrix
	
	Return      : DotProductVector
	ReturnType  : Vector
	
	Description : ベクトルと行列のドット積を求める関数
 */
Vector solveDotProduct(Vector v, Matrix m) {
  Vector vector = {v.a*m.a + v.b*m.c
						 ,v.a*m.b + v.b*m.d};
  return vector;
}

/**
	FunctionName: solveMatrixInverse
	
	Argument    : m
	ArgumentType: Matrix
	
	Return      : MatrixInverse
	ReturnType  : Matrix
	
	Description : 渡された行列の逆行列を求める関数
 */
Matrix solveMatrixInverse(Matrix m) {
  float scala = 1/(m.a*m.d - m.b*m.c);
  Matrix matInv = {scala*m.d, scala*(-1)*m.b
						 ,scala*(-1)*m.c, scala*m.a};
  //TODO N次元行列に対応させる
  return matInv;
}

/**
	FunctionName: countFloat
	
	Argument    : f
	ArgumentType: ListOfFloat
	
	Return      : ElementCount
	ReturnType  : integer
	
	Description : 渡された単精度浮動点小数リストの要素数を数える関数
 */
int countFloat(Float* f) {
  int count = 0;
  Float* currentFloat = f;
  while (currentFloat != NULL) {
	 currentFloat = currentFloat -> nextPt;
	 count++;
  }
  return count;
}

/**
	FunctionName: findRange
	
	Argument    : f
	ArgumentType: ListOfFloat
	
	Return      : range{min, max}
	ReturnType  : Pair
	
	Description : 渡された単精度浮動点小数リストの総和を求める関数
 */
Pair findRange(Float* f) {
  Float* currentFloat = f;
  Pair range = {f -> n, f -> n};
  while (currentFloat != NULL) {
	 if (currentFloat -> n < range.n) {
		range.n = currentFloat -> n;
	 }
	 if (currentFloat -> n > range.m) {
		range.m = currentFloat -> n;
	 }
	 currentFloat = currentFloat -> nextPt;
  }
  return range;
}

/**
	FunctionName: solveSigma
	
	Argument    : f1, f2
	ArgumentType: ListOfFloat, ListOfFloat
	
	Return      : SummationOfFloat
	ReturnType  : float
	
	Description : 渡された単精度浮動点小数リストの総和を求める関数
 */
float solveSigma(Float* f1, Float* f2) {
  float sum = 0;
  if (f1 == NULL && f2 == NULL) {
	 printf("IllegalArgumentsError\n");
	 exit(-1);
  }
  else if (f1 != NULL && f2 != NULL) {
	 Float *currentFloat1 = f1;
	 Float *currentFloat2 = f2;
	 while (currentFloat1 != NULL || currentFloat2 != NULL) {
		sum += currentFloat1 -> n * currentFloat2 -> n;
		currentFloat1 = currentFloat1 -> nextPt;
		currentFloat2 = currentFloat2 -> nextPt;
	 }
	 return sum;
  }
  else if (f1 != NULL || f2 != NULL) {
	 Float *currentFloat;
	 if (f1 == NULL) {
		currentFloat = f2;
	 }
	 else if (f2 == NULL) {
		currentFloat = f1;
	 }
	 while (currentFloat != NULL) {
		sum += currentFloat -> n;
		currentFloat = currentFloat -> nextPt;
	 }
	 return sum;
  }
  return sum;
}


/**
	FunctionName: splitToFloat
	
	Argument    : p, f1, f2
	ArgumentType: ListOfPair, PointerToListOfFloat, PointerToListOfFloat
	
	Return      : void
	ReturnType  : void
	
	Description : ペアで渡された座標をX、Yに分ける関数
 */
void splitToFloat(Pair* p, Float** f1, Float** f2) {
  Pair *currentPair = p;
  while (currentPair != NULL) {
	 Float *newFloat = (Float*) malloc(sizeof(Float));
	 if (newFloat == NULL) {
		printf("MemoryAllocationError\n");
		exit(-1);
	 }
	 newFloat -> n = currentPair -> n;
	 newFloat -> nextPt = NULL;
	 if (*f1 == NULL) {
		*f1 = newFloat;
	 } else {
		Float *currentFloat = *f1;
		while (currentFloat -> nextPt != NULL) {
		  currentFloat = currentFloat -> nextPt;
		}
		currentFloat -> nextPt = newFloat;
	 }
	 newFloat = (Float*) malloc(sizeof(Float));
	 if (newFloat == NULL) {
		printf("MemoryAllocationError\n");
		exit(-1);
	 }
	 newFloat -> n = currentPair -> m;
	 newFloat -> nextPt = NULL;
	 if (*f2 == NULL) {
		*f2 = newFloat;
	 } else {
		Float *currentFloat = *f2;
		while (currentFloat -> nextPt != NULL) {
		  currentFloat = currentFloat -> nextPt;
		}
		currentFloat -> nextPt = newFloat;
	 }
	 currentPair = currentPair -> nextPt;
  }
}

/**
	FunctionName: loadCSV
	
	Argument    : filename
	ArgumentType: String
	
	Return      : ListOfCoordinate
	ReturnType  : ListOfPair
	
	Description : 座標の入っているCSVファイルからデータをペアでロードしてくる関数
 */
Pair* loadCSV(char* filename) {
  FILE *fp;
  fp = fopen(filename, "r");
  if (fp == NULL) {
	 printf("FileNotFoundError\n");
	 exit(-1);
  }
  Pair *points = NULL;
  float x, y;
  while (fscanf(fp, "%f, %f\n", &x, &y) != EOF) {
	 Pair *newPoint = (Pair*) malloc(sizeof(Pair));
	 if (newPoint == NULL) {
		printf("MemoryAllocationError\n");
		exit(-1);
	 }
	 newPoint -> n = x;
	 newPoint -> m = y;
	 newPoint -> nextPt = NULL;
	 if (points == NULL) {
		points = newPoint;
	 } else {
		Pair *currentPoint = points;
		while (currentPoint -> nextPt != NULL) {
		  currentPoint = currentPoint -> nextPt;
		}
		currentPoint -> nextPt = newPoint;
	 }
  }
  fclose(fp);
  return points;
}
