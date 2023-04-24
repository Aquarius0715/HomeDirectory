/**
	各ヘッダーのインクルード
 */
#include <stdio.h>   /* 各入出力に使用 */
#include <stdlib.h>  /* 乱数生成に使用 */
#include <time.h>    /* 乱数のシードを初期化するために使用 */
#include <ctype.h>   /* 入力を大文字に揃える時に使用 */

/**
	各変数、列挙の宣言
 */
/* ソートの種類を列挙 */
typedef enum SortClass {
  SELECTION_SORT,
  BUBBLE_SORT,
  QUICK_SORT,
  RADIX_SORT,
  NONE_SORT_CLASS
} SortClass;

/* 昇順か降順かを列挙 */
typedef enum SortType {
  ASCENDING,
  DESCENDING,
  NONE_SORT_TYPE
} SortType;

/* ソートするデータ形式を列挙 */
typedef enum DataType {
  ORDERED_ASCENDING,
  ORDERED_DESCENDING,
  RANDOM,
  PARTIALLY_ORDERED_ASCENDING,
  PARTIALLY_ORDERED_DESCENDING,
  NONE_DATA_TYPE
} DataType;

/* ソート結果を格納する構造体を定義 */
typedef struct ResultSet {
  SortClass E_sortClass;
  SortType E_sortType;
  DataType E_dataType;
  int compareCount;
  int swapCount;
  int* result;
} ResultSet;

int NUMBER= -1;           /* 配列の大きさの変数 */
double RATIO = -1;
SortClass E_sortClass = NONE_SORT_CLASS; /* ソートの種類を格納する変数 */
SortType E_sortType = NONE_SORT_TYPE;   /* 昇順か降順かを格納する変数 */
DataType E_dataType = NONE_DATA_TYPE;   /* ソートするデータの形式を格納する変数 */

int* array = NULL;        /* ソートするデータを格納するポインタ配列 */

/**
	各関数のプロトタイプ宣言
 */
char* sortClass(SortClass E_sortClass);
char* sortType(SortType E_sortType);
char* dataType(DataType E_dataType);

void initialSetting();
int* generateArray();
void sort();

int* createOrderedData(SortType E_sortType);
int* createRandomData();
int* createPartiallyOrderedData(SortType E_sortType, double ratio);

ResultSet selectionSort(SortType E_sortType);
ResultSet bubbleSort(SortType E_sortType);
ResultSet quickSort(SortType E_sortType, int* num, int left, int right, int compareCount, int swapCount);
ResultSet radixSort(SortType E_sortType);

int* copyArray(int* original, int* copyTo);
int* showArray(int* array1);
void showResult(ResultSet result);
void showSettings();
int* swapElement(int* array1, int p1, int p2);
int getMaxRadix(int n);



/**
	メイン関数
 */
int main(void) {
  char keyBoardInput, options;
  while (1) {
	 system("clear");
	 showSettings();
	 printf("S: ソート, R: ソートデータの再設定, Q: 終了\n");
	 printf("Type desired options(S, R, H, Q)");
	 scanf("%s", &keyBoardInput);
	 options = toupper(keyBoardInput);
	 switch (options) {
	 case 'S':
		E_sortClass = NONE_SORT_CLASS;
		E_sortType = NONE_SORT_TYPE;
		initialSetting();
		sort();
		break;
	 case 'R':
		NUMBER = -1;
		E_dataType = NONE_DATA_TYPE;
		free(array);
		initialSetting();
		break;
	 case 'Q':
		free(array);
		return 0;
	 }
  }
}

char* sortClass(SortClass E_sortClass) {
  switch (E_sortClass) {
  case SELECTION_SORT:
	 return "単純選択ソート";
  case BUBBLE_SORT:
	 return "バブルソート";
  case QUICK_SORT:
	 return "クイックソート";
  case RADIX_SORT:
	 return "基数ソート";
  case NONE_SORT_CLASS:
	 return "選択なし";
  }
  return NULL;
}

char* sortType(SortType E_sortType) {
  switch (E_sortType) {
  case ASCENDING:
	 return "昇順";
  case DESCENDING:
	 return "降順";
  case NONE_SORT_TYPE:
	 return "選択なし";
  }
  return NULL;
}

char* dataType(DataType E_dataType) {
  switch (E_dataType) {
  case ORDERED_ASCENDING:
	 return "昇順にソートされたデータ";
  case ORDERED_DESCENDING:
	 return "降順にソートされたデータ";
  case RANDOM:
	 return "ランダムなデータ";
  case PARTIALLY_ORDERED_ASCENDING:
	 return "一部が昇順に並んだデータ";
  case PARTIALLY_ORDERED_DESCENDING:
	 return "一部が降順に並んだデータ";
  case NONE_DATA_TYPE:
	 return "選択なし";
  }
  return NULL;
}

void initialSetting() {
  system("clear");
  if (NUMBER == -1) {
	 while (NUMBER < 1) {
		printf("Type Array Size: ");
		scanf("%d", &NUMBER);
	 }
	 array = (int*) malloc(sizeof(int) * NUMBER);
  }

  int selection = -1;
  if (E_sortClass == NONE_SORT_CLASS) {
	 system("clear");
	 while (selection < 0 || selection > 3) {
		system("clear");
		printf("0: Selection Sort\n");
		printf("1: Bubble Sort\n");
		printf("2: Quick Sort\n");
		printf("3: Radix Sort\n");
		printf("Type Sort Algorythm: : ");
		scanf("%d", &selection);
	 }
	 E_sortClass = selection;
  }

  if (E_sortType == NONE_SORT_TYPE) {
	 system("clear");
	 selection = -1;
	 while (selection < 0 || selection > 1) {
		system("clear");
		printf("0: Ascending\n");
		printf("1: Descending\n");
		printf("Type Sort Order: ");
		scanf("%d", &selection);
	 }
	 E_sortType = selection;
  }

  if (E_dataType == NONE_DATA_TYPE) {
	 system("clear");
	 selection = -1;
	 srand((unsigned int) time(NULL));
	 while (selection < 0 || selection > 4) {
		system("clear");
		printf("0: OrderedAscending\n");
		printf("1: OrderedDescending\n");
		printf("2: Random\n");
		printf("3: PartiallyOrderedAscending\n");
		printf("4: PartiallyOrderedDescending\n");
		printf("Type Data Type: ");
		scanf("%d", &selection);
	 }
	 E_dataType = selection;
	 system("clear");

	 if (E_dataType == 3 || E_dataType == 4) {
		printf("Type sort ratio(range[0.0 ~ 1.0]): ");
		scanf("%lf", &RATIO);
		system("clear");
	 }
	 generateArray();
  }
  system("clear");
}

int* generateArray() {
  int *result;
  switch (E_dataType) {
  case ORDERED_ASCENDING:
	 result = createOrderedData(ASCENDING);
	 break;
  case ORDERED_DESCENDING:
	 result = createOrderedData(DESCENDING);
	 break;
  case RANDOM:
	 result = createRandomData();
	 break;
  case PARTIALLY_ORDERED_ASCENDING:
	 result = createPartiallyOrderedData(ASCENDING, RATIO);
	 break;
  case PARTIALLY_ORDERED_DESCENDING:
	 result = createPartiallyOrderedData(DESCENDING, RATIO);
	 break;
  case NONE_DATA_TYPE:
	 initialSetting();
	 break;
  default:
	 result = NULL;
  }
  return result;
}

void sort() {
  ResultSet result;
  switch(E_sortClass) {
  case SELECTION_SORT: 
	 result = selectionSort(E_sortType);
	 break;
  case BUBBLE_SORT: 
	 result = bubbleSort(E_sortType);
	 break;
  case QUICK_SORT:
	 result = quickSort(E_sortType, NULL, 0, NUMBER - 1, 0, 0);
	 break;
  case RADIX_SORT:
	 result = radixSort(E_sortType);
	 break;
  case NONE_SORT_CLASS:
	 initialSetting();
	 break;
  }
  showResult(result);
  printf("\n");
  printf("Enterで確認画面を終了");
  getchar();
  getchar();
  system("clear");
}

int* createOrderedData(SortType E_sortType) {
  array = createRandomData();
  array = selectionSort(E_sortType).result;
  return array;
}

int* createRandomData() {
  for (int i = 0; i < NUMBER; i++) {
	 array[i] = rand() % NUMBER + 1;
  }
  return array;
}

int* createPartiallyOrderedData(SortType E_sortType, double ratio) {
  createOrderedData(E_sortType);
  switch (E_sortType) {
  case ASCENDING:
	 for (int i = NUMBER - (NUMBER * ratio); i < NUMBER; i++) {
		array[i] = rand() % NUMBER + 1;
	 }
	 break;
  case DESCENDING:
	 for (int i = 0; i < NUMBER - (NUMBER * ratio); i++) {
		array[i] = rand() % NUMBER + 1;
	 }
	 break;
  case NONE_SORT_TYPE:
	 exit(-4);
  }
  return array;
}

ResultSet selectionSort(SortType E_sortType) {
  int* num = (int*) malloc(sizeof(int) * NUMBER);
  num = copyArray(array, num);
  int compareCount = 0;
  int swapCount = 0;
  for (int i = 0; i < NUMBER - 1; i++) {
	 int min = num[i];
	 int k = i;
	 for (int j = i + 1; j < NUMBER; j++) {
		compareCount++;
		switch (E_sortType) {
		case ASCENDING:
		  if (num[j] < min) {
			 min = num[j];
			 k = j;
		  }
		  break;
		case DESCENDING:
		  if (num[j] > min) {
			 min = num[j];
			 k = j;
		  }
		  break;
		case NONE_SORT_TYPE:
		  exit(-1);
		}
	 }
	 swapElement(num, i, k);
	 swapCount++;
  }
  ResultSet result = {E_sortClass, E_sortType, E_dataType, compareCount, swapCount, num};
  return result;
}

ResultSet bubbleSort(SortType E_sortType) {
  int* num = (int*) malloc(sizeof(int) * NUMBER);
  num = copyArray(array, num);
  int compareCount = 0;
  int swapCount = 0;
  for (int i = 0; i < NUMBER - 1; i++) {
	 for (int j = NUMBER - 1; j > i; j--) {
		compareCount++;
		switch (E_sortType) {
		case ASCENDING:
		  if (num[j - 1] > num[j]) {
			 swapElement(num, j - 1, j);
			 swapCount++;
		  }
		  break;
		case DESCENDING:
		  if (num[j - 1] < num[j]) {
			 swapElement(num, j - 1, j);
			 swapCount++;
		  }
		  break;
		case NONE_SORT_TYPE:
		  exit(-2);
		}
	 }
  }
  ResultSet result = {E_sortClass, E_sortType, E_dataType, compareCount, swapCount, num};
  return result;
}

ResultSet quickSort(SortType E_sortType, int* num, int left, int right, int compareCount, int swapCount) {
  if (num == NULL) {
	 num = (int*) malloc(sizeof(int) * NUMBER);
	 num = copyArray(array, num);
  }
  int base = num[(left + right) / 2];
  int L = left;
  int R = right;
  while (1) {
	 switch (E_sortType) {
	 case ASCENDING:
		while (num[L] < base) {
		  compareCount++;
		  L++;
		}
		while (base < num[R]) {
		  compareCount++;
		  R--;
		}
		break;
	 case DESCENDING:
		while (num[L] > base) {
		  compareCount++;
		  L++;
		}
		while (base > num[R]) {
		  compareCount++;
		  R--;
		}
		break;
	 case NONE_SORT_TYPE:
		exit(-3);
	 }
	 if (L >= R) {
		compareCount++;
		break;
	 }
	 swapElement(num, L, R);
	 swapCount++;
	 L++;
	 R--;
  }
  if (left < L - 1) {
	 quickSort(E_sortType, num, left, right - 1, compareCount, swapCount);
  }
  if (R + 1 < right) {
	 quickSort(E_sortType, num, R + 1, right, compareCount, swapCount);
  }
  ResultSet result = {E_sortClass, E_sortType, E_dataType, compareCount, swapCount, num};
  return result;
}

ResultSet radixSort(SortType E_sortType) {
  int* num = (int*) malloc(sizeof(int) * NUMBER);
  int compareCount = -1;
  int swapCount = -1;
  int radArray[NUMBER];
  int temp[NUMBER];
  num = copyArray(array, num);
  int maxRadix = getMaxRadix(NUMBER);
  int currentDigit = 1;
  while (currentDigit <= maxRadix) {
	 for (int i = 0; i < NUMBER; i++) {
		radArray[i] = (num[i] / currentDigit) % 10;
	 }
	 int k = 0;
	 switch (E_sortType) {
	 case ASCENDING:
		for (int i = 0; i <= 9; i++) {
		  for (int j = 0; j < NUMBER; j++) {
			 if (radArray[j] == i) {
				temp[k++] = num[j];
				swapCount++;
			 }
		  }
		}
		break;
	 case DESCENDING:
		for (int i = 9; i >= 0; i--) {
		  for (int j = 0; j < NUMBER; j++) {
			 if (radArray[j] == i) {
				temp[k++] = num[j];
				swapCount++;
			 }
		  }
		}
		break;
	 case NONE_SORT_TYPE:
		exit(-5);
	 }
	 for (int i = 0; i < NUMBER; i++) {
		num[i] = temp[i];
		swapCount++;
	 }
	 currentDigit *= 10;
  }
  ResultSet result = {E_sortClass, E_sortType, E_dataType, compareCount, swapCount, num};
  return result;
}

int* copyArray(int* original, int* copyTo) {
  for (int i = 0; i < NUMBER; i++) {
	 copyTo[i] = original[i];
  }
  return copyTo;
}

int* showArray(int* array1) {
  for (int i = 0; i < NUMBER; i++) {
	 printf("%d ", array1[i]);
  }
  printf("\n");
  return array1;
}

void showResult(ResultSet result) {
  printf("ソート前の配列: ");
  showArray(array);
  printf("\n");
  printf("ソート後の配列: ");
  showArray(result.result);
  printf("\n");
  printf("ソートの種類: %s\n", sortClass(result.E_sortClass));
  printf("ソートのタイプ: %s\n", sortType(result.E_sortType));
  printf("ソートする配列のデータ: %s\n", dataType(result.E_dataType));
  if (E_dataType == PARTIALLY_ORDERED_ASCENDING || E_dataType == PARTIALLY_ORDERED_DESCENDING) {
	 printf("ソートされている割合: %.1f\n", RATIO);
  }
  printf("\n");
  if (result.compareCount == -1) {
	 printf("比較回数: - 回\n");
  } else {
	 printf("比較回数: %d 回\n", result.compareCount);
  }
  printf("交換回数: %d 回\n", result.swapCount);
}

void showSettings() {
  printf("-----現在のデータ形式-----\n");
  printf("配列の長さ: ");
  if (NUMBER == -1) {
	 printf("選択なし\n");
  } else {
	 printf("%d\n", NUMBER);
  }
  printf("データ形式: %s\n", dataType(E_dataType));
  if (E_dataType == PARTIALLY_ORDERED_ASCENDING || E_dataType == PARTIALLY_ORDERED_DESCENDING) {
	 printf("ソートされている割合: %.1f\n", RATIO);
  }
  showArray(array);
  printf("--------------------------\n");
}

int* swapElement(int* array1, int p1, int p2) {
  int temp;
  temp = array1[p1];
  array1[p1] = array1[p2];
  array1[p2] = temp;
  return array1;
}

int getMaxRadix(int n) {
  int radix = 1;
  while (n != 0) {
	 radix *= 10;
	 n /= 10;
  }
  return radix;
}
