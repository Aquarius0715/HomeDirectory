/* 各ヘッダのインクルード */
#include <stdio.h>  // 各入出力に使用
#include <stdlib.h> // 乱数、exitなどに使用
#include <time.h>   // 乱数シードの初期化、時間計測に使用
#include <unistd.h> // プログラムを一時的に止めるために使用

/* 各列挙の定義 */
/** Boolean列挙。真と偽どちらかの状態をとる
	 E_FALSE: 偽
	 E_TRUE : 真
 */
typedef enum Boolean {
  E_FALSE,
  E_TRUE
} Boolean;

/** Result列挙。ゲームの結果の列挙
	 E_WIN     : 勝ち
	 E_LOSE    : 負け
	 E_CONTINUE: 継続
 */
typedef enum Result {
  E_WIN,
  E_LOSE,
  E_CONTINUE
} Result;


/* 各構造体の定義 */
/** Cell構造体
	 ボードの一つ一つのセルの状態を格納する。
	 display(Character)        : ボードに表示する文字を格納する
	 isBomb(Boolean)           : セルが地雷であるかどうかを格納する
	 isOpen(Boolean)           : セルが開いているかどうかを格納する
	 isMark(Boolean)           : セルがマークされているかを格納する
	 _BOARD_SIZE(ConstInteger) : ボードの大きさを格納する
	 _BOMBS_COUNT(ConstInteger): ボード内の地雷の数を格納する 
 */
typedef struct Cell {
  char display;
  Boolean isBomb;
  Boolean isOpen;
  Boolean isMark;
  int _BOARD_SIZE;
  int _BOMBS_COUNT;
} Cell;

/** PairInt構造体
	 2つの整数値をペアにして格納する。主に座標に使われている。
	 i(Integer)      : 1つ目の要素
	 j(Integer)      : 2つ目の要素
	 next(OwnPointer): リストを想定する際の次のデータの位置
 */
typedef struct PairInt {
  int i;
  int j;
  struct PairInt* next;
} PairInt;

/** Command構造体
	 成形された入力データを格納する
	 coordinate(PairInt): 指定された座標
	 option(Character)  : コマンドオプション
 */
typedef struct Command {
  PairInt coordinate;
  char option;
} Command;

/** Time構造体
	 成形した時間データを格納する
	 hours(Integer)  : 時間
	 minuts(Integer) : 分
	 seconds(Integer): 秒 
 */
typedef struct Time {
  int hours;
  int minuts;
  int seconds;
} Time;

/* 各関数のプロトタイプ宣言 */
void displayBoard(Cell** board);
void displayResult(Result result, time_t startTime, time_t endTime);
int strToInt(char* str);
int strLen(char* str);
Cell** initBoard(int boardSize, int bombsCount);
void freeBoard(Cell** board);
int randomMinToMax(int min, int max);
void swapCell(Cell** board, PairInt from, PairInt to);
Command input(char* message);
Result game(Cell** board);
Result checkAroundCell(Cell** board, PairInt coordinate);
PairInt* findAroundCoordinate(Cell** board, PairInt centerCoordinate);
char intToChar(int n);
Boolean isOption(char c);
int charToInt(char c);
int findDigitCount(int n);
Result markCell(Cell** board, PairInt coordinate);
Result scanBomb(Cell** board, PairInt coordinate);
Result markQuestion(Cell** board, PairInt coordinate);

/* メイン関数 */
int main(int argc, char* argv[]) {
  // コマンドライン引数長が3ではない時使い方を表示する
  if (argc != 3) {
	 printf("NoMatchArgumentError\n");
	 printf("usage: ./msweeper <BoardSize> <BombsCount>\n");
	 return -1;
  }

  // 乱数シードを時間で初期化
  srand((unsigned) time(NULL));

  // コマンドライン引数から盤面の大きさと地雷の数を定義する
  const int _BOARD_SIZE = strToInt(argv[1]);
  const int _BOMBS_COUNT = strToInt(argv[2]);

  // 時間計測のための変数
  time_t startTime, endTime;

  // 盤面データを格納しておく変数
  Cell **board = NULL;

  // 盤面データを初期化する
  board = initBoard(_BOARD_SIZE, _BOMBS_COUNT);

  // 開始時刻を格納する
  startTime = time(NULL);

  // ゲームを開始する
  Result result = game(board);

  // 終了時刻を格納する
  endTime = time(NULL);

  // 結果を出力する
  displayResult(result, startTime, endTime);

  // 盤面のメモリ解放を行う
  freeBoard(board);
  return 0;
}

/** secondsToTime関数
	 description: 秒数を与えると時間の情報を返す関数
	 args       : time(time_t)
	 return     : 成形された時間データ(Time)
 */
Time secondsToTime(time_t time) {
  if (time < 60) {
	 return (Time) {0, 0, time};
  } else if (time < 3600) {
	 return (Time) {0, time / 60, time % 60};
  } else {
	 return (Time) {time / 3600, (time % 3600) / 60, time % 60};
  }
}

/** displayResult関数
	 description: ゲームの結果を出力する関数。同時に経過時間も出力する。
	 args       : result(Result), startTime(time_t), endTime(time_t)
	 return     : なし(void)
 */
void displayResult(Result result, time_t startTime, time_t endTime) {
  switch (result) {
  case E_WIN:
	 printf("あなたの勝ちです\n");
	 break;
  case E_LOSE:
	 printf("あなたの負けです\n");
	 break;
  default:
	 break;
  }
  Time time = secondsToTime(endTime - startTime);
  printf("タイム: ");
  if (time.hours > 0) {
	 printf("%d時間", time.hours);
  }
  if (time.minuts > 0) {
	 printf("%d分", time.minuts);
  }
  if (time.seconds > 0) {
	 printf("%d秒", time.seconds);
  }
  printf("\n");
}


/** game関数
	 desctiption: ゲームの根幹の関数。この関数でコマンドの入力からさまざまな操作に分岐する。
	 args       : board(DoublePointerOfCell)
	 return     : そのターンの結果(Result)
 */
Result game(Cell** board) {
  Result result;
  do {
	 system("clear");
	 displayBoard(board);
	 Command command = input("Input command: ");
	 if (command.coordinate.i < 0 || command.coordinate.i > (board[0][0]._BOARD_SIZE - 1)
		  || command.coordinate.j < 0 || command.coordinate.j > (board[0][0]._BOARD_SIZE - 1)) {
		result = E_CONTINUE;
		printf("InputNumberOutOfRange(0~%d)\n", board[0][0]._BOARD_SIZE - 1);
		sleep(3);
		continue;
	 }
	 switch (command.option) {
	 case 's':
		result = checkAroundCell(board, command.coordinate);
		break;
	 case 'm':
		result = markCell(board, command.coordinate);
		break;
	 case 'q':
		result = markQuestion(board, command.coordinate);
		break;
	 default:
		printf("Input invalid. Retry to input your character.\n");
		result = E_CONTINUE;
		sleep(3);
		break;
	 }
  } while (result == E_CONTINUE);
  return result;
}

/** markQuestion関数
	 description: 盤面に？マークをつける関数。
	 args       : board(DoublePointerOfCell), coordinate(PairInt)
	 return     : クエスチョンマークをつけた結果(Result)
*/
Result markQuestion(Cell** board, PairInt coordinate) {
  if (board[coordinate.i][coordinate.j].display == '.'){
	 board[coordinate.i][coordinate.j].display = '?';
	 return E_CONTINUE;
  }
  return E_CONTINUE;
}

/** scamBomb関数
	 description: 盤面全体が空いていたら勝利を、相手いなかったら継続を送る関数
	 args       : board(DoublePointerOfCell), coordinate(PairInt)
	 return     : スキャンをした結果(Result)
 */
Result scanBomb(Cell** board, PairInt coordinate) {
  int correctCount = 0;
  for (int i = 0; i < board[0][0]._BOARD_SIZE; i++) {
	 for (int j = 0; j < board[0][0]._BOARD_SIZE; j++) {
		if (board[i][j].display == '.' || board[i][j].display == '?') {
		  return E_CONTINUE;
		}
	 }
  }
  return E_WIN;
}

/** markCell関数
	 description: 指定したセルにマークをつける。もし間違っていたら敗北を、あっていれば継続を送る関数
	 args       : board(DoublePointerOfCell), coordinate(PairInt)
	 return     : マークをした結果(Result)
 */
Result markCell(Cell** board, PairInt coordinate) {
  if (board[coordinate.i][coordinate.j].isOpen) {
	 return E_CONTINUE;
  }
  if (board[coordinate.i][coordinate.j].isMark) {
	 return E_CONTINUE;
  }
  if (!board[coordinate.i][coordinate.j].isBomb) {
	 return E_LOSE;
  }
  board[coordinate.i][coordinate.j].isMark = E_TRUE;
  checkAroundCell(board, coordinate);
  board[coordinate.i][coordinate.j].display = 'M';
  return scanBomb(board, coordinate);
}

/** checkAroundCell関数
	 description: 指定したセルの周りのセルの地雷数を確認していく。もし隣の地雷数が０であったら自動的にその隣も開ける。
	 args       : board(DoublePointerOfCell), coordinate(PairInt)
	 return     : 指定したセルを開けた結果(Result)
 */
Result checkAroundCell(Cell** board, PairInt coordinate) {
  if (board[coordinate.i][coordinate.j].isBomb && !board[coordinate.i][coordinate.j].isMark) {
	 return E_LOSE;
  }
  if (board[coordinate.i][coordinate.j].isOpen) {
	 return E_CONTINUE;
  }
  PairInt* arounds = findAroundCoordinate(board, coordinate);
  int bombsCounter = 0;
  PairInt* currentArounds = arounds;
  board[coordinate.i][coordinate.j].isOpen = E_TRUE;
  while (currentArounds != NULL) {
	 if (board[currentArounds -> i][currentArounds -> j].isBomb) {
		bombsCounter++;
	 }
	 currentArounds = currentArounds -> next;
  }
  if (bombsCounter == 0) {
	 board[coordinate.i][coordinate.j].display = ' ';
	 currentArounds = arounds;
	 while (currentArounds != NULL) {
		checkAroundCell(board, *currentArounds);
		currentArounds = currentArounds -> next;
	 }
  } else {
	 printf("%d\n", board[coordinate.i][coordinate.j].isMark);
	 board[coordinate.i][coordinate.j].display = intToChar(bombsCounter);
  }
  free(arounds);
  return scanBomb(board, coordinate);
}

/** findAroundsCoordinate関数
	 description: 指定したセルの座標の周りの座標を計算する関数
	 args       : board(DoublePointerOf), center(PairInt)
	 return 指定したセルの周りの座標のリスト(ListOfPairInt)
 */
PairInt* findAroundCoordinate(Cell** board, PairInt center) {
  PairInt *arounds = NULL;
  for (int i = -1; i <= 1; i++) {
	 for (int j = -1; j <= 1; j++) {
		if (center.i + i < 0 || center.j + j < 0) continue;
		if (center.i + i > board[0][0]._BOARD_SIZE - 1 || center.j + j > board[0][0]._BOARD_SIZE - 1) continue;
		
		PairInt *newPairInt = (PairInt*) malloc(sizeof(PairInt));
		if (newPairInt == NULL) {
		  printf("MemoryAllocationError\n");
		  exit(-1);
		}
		newPairInt -> i = center.i + i;
		newPairInt -> j = center.j + j;
		newPairInt -> next = NULL;
		if (arounds == NULL) {
		  arounds = newPairInt;
		} else {
		  PairInt *currentPairInt = arounds;
		  while (currentPairInt -> next != NULL) {
			 currentPairInt = currentPairInt -> next;
		  }
		  currentPairInt -> next = newPairInt;
		}
	 }
  }
  return arounds;
}

/** input関数
	 description: コマンドラインからコマンドを取得しデータを成形して渡す関数
	 args       : message(string)
	 return     : 成形されたコマンドデータ(Command)
 */
Command input(char* message) {
  int x, y;
  char option;
  printf("%s", message);
  scanf("%d %d %c", &y, &x, &option);
  scanf("%*[^\n]");
  scanf("%*c");
  printf("\n\n");
  return (Command) {(PairInt) {x, y, NULL}, option};
}

void freeBoard(Cell** board) {
  for (int i = 0; i < board[0][0]._BOARD_SIZE; i++) {
	 free(board[i]);
  }
}

/** initBoard関数
	 description: 盤面を新しく作成する関数
	 args       : boardSize(Integer), bombsCount(Integer)
	 return     : 新しい盤面データ(DoublePointerOfCell)
 */
Cell** initBoard(int boardSize, int bombsCount) {
  Cell** board = NULL;
  const int _BOMBS_COUNT = bombsCount;
  board = (Cell**) malloc(sizeof(Cell*) * boardSize);
  if (board == NULL) {
	 printf("MemoryAllocationError\n");
	 exit(-1);
  }
  for (int i = 0; i < boardSize; i++) {
	 board[i] = (Cell*) malloc(sizeof(Cell) * boardSize);
	 if (board[i] == NULL) {
		printf("MemoryAllocationError\n");
		exit(-1);
	 }
  }
  for (int i = 0; i < boardSize; i++) {
	 for (int j = 0; j < boardSize; j++) {
		if (bombsCount != 0) {
		  Cell newCell = {'.', E_TRUE, E_FALSE, E_FALSE, boardSize, _BOMBS_COUNT};
		  board[i][j] = newCell;
		  bombsCount --;
		} else {
		  Cell newCell = {'.', E_FALSE, E_FALSE, E_FALSE,  boardSize, _BOMBS_COUNT};
		  board[i][j] = newCell;
		}
	 }
  }
  for (int i = 0; i < boardSize; i++) {
	 for (int j = 0; j < boardSize; j++) {
		PairInt from = {i, j};
		PairInt to = {randomMinToMax(0, boardSize - 1), randomMinToMax(0, boardSize - 1)};
		swapCell(board, from , to);
	 }
  }
  return board;
}

/** randomMinToMax関数
	 description: 指定された最小から最大の数の範囲で乱数を生成する関数
	 args       : min(Integer), max(Integer)
	 return     : 指定された範囲内の乱数(Integer)
 */
int randomMinToMax(int min, int max) {
  int rnd = rand() % (max - min) + min;
  return rnd;
}

/** swapCell関数
	 description: 指定されたセルを移動先のセルと交換する関数
	 args       : board(DoublePointerOfCell), from(PairInt), to(PairInt)
	 return     : なし(void)
 */
void swapCell(Cell** board, PairInt from, PairInt to) {
  Cell temp;
  temp = board[from.i][from.j];
  board[from.i][from.j] = board[to.i][to.j];
  board[to.i][to.j] = temp;
}

/** strLen関数
	 description: 渡された文字列の文字列長を数える関数
	 args       : str(string)
	 return     : 渡された文字列の文字列長(Integer)
 */
int strLen(char* str) {
  int count = 0;
  while (str[count] != '\0') {
	 count++;
  }
  return count;
}

/** strToInt関数
	 description: 渡された文字列での数字を整数型に変換する関数
	 args       : str(string)
	 return     : 変換された数字データ(Integer)
 */
int strToInt(char* str) {
  int digit = 1;
  int num = 0;
  for (int i = strLen(str) - 1; i >= 0; i--) {
	 if (str[i] < '0' || str[i] > '9') {
		printf("NumberFormatError\n");
		exit(-1);
	 }
	 num += (str[i] - '0') * digit;
	 digit *= 10;
  }
  return num;
}

/** charToInt関数
	 description: 渡された文字での数字を整数型に変換する関数
	 args       : c(Character)
	 return     : 変換された数字データ(Integer)
 */
int charToInt(char c) {
  if (c < '0' || c > '9') {
	 printf("NumberFormatError\n");
	 exit(-1);
  }
  return c - '0';
}

/** intToChar関数
	 description: 渡された数値を文字に変換する関数
	 args       : n(Integer)
	 return     : 変換された文字データ(Character)
 */
char intToChar(int n) {
  if (n < 0 || n > 9) {
	 printf("NumberFormatError\n");
	 exit(-1);
  }
  return n + '0';
}

/** isOption関数
	 description: 渡された文字がコマンドのオプションかどうかを判定する関数
	 args       : c(Character)
	 return     : 渡された文字がオプションかどうかの真偽値(Boolean)
 */
Boolean isOption(char c) {
  if (c == 'q' || c == 's' || c == 'm') {
	 return E_TRUE;
  } else {
	 return E_FALSE;
  }
}

/** findDigitCount関数
	 description: 渡された数値の桁数を数える関数
	 args       : n(Integer)
	 return     : 渡された数値の桁数(Integer)
 */
int findDigitCount(int n) {
  int digitCount = 0;
  while (n != 0 || digitCount == 0) {
	 n /= 10;
	 digitCount ++;
  }
  return digitCount;
}

/** displayBoard関数
	 description: 渡された盤面データをコンソールに出力する関数
	 args       : board(DoublePointerOfCell)
	 return     : なし(void)
 */
void displayBoard(Cell** board) {
  const int _SIZE = board[0][0]._BOARD_SIZE;
  printf("*** M Sweeper***\n");
  printf("地雷の総数: %d\n", board[0][0]._BOMBS_COUNT);
  printf("コマンドの入力:x y [a or s or m]\n");
  printf("x y : 座標[0-%d]\n", _SIZE - 1);
  printf("s   : (x, y)を安全な点としてチェック\n");
  printf("m   : (x, y)にMマークをつける\n");
  printf("q   : (x, y)に?マークをつける\n");
  printf("\n  ");
  for (int i = 0; i < _SIZE; i++) {
	 for (int j = 0; j < findDigitCount(_SIZE) - findDigitCount(i) + 1 && findDigitCount(_SIZE) > 1; j++) {
		printf(" ");
	 }
	 printf("%d ", i);
  }
  printf("\n");
  for (int i = 0; i < _SIZE; i++) {
	 for (int j = 0; j < findDigitCount(_SIZE) / 2; j++) {
		printf("\n");
	 }
	 printf("%d ", i);
	 for (int j = 0; j < _SIZE; j++) {
		if (j == 0) {
		  for (int k = 0; k < findDigitCount(_SIZE) - findDigitCount(i) + 1 && findDigitCount(_SIZE) > 1; k++) {
			 printf(" ");
		  }
		} else {
		  for (int k = 0; k < findDigitCount(_SIZE) && findDigitCount(_SIZE) > 1; k++) {
			 printf(" ");
		  }
		}
		printf("%c ", board[i][j].display);
	 }
	 printf("\n");
  }
}
