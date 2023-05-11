/** 各ヘッダーのインクルード */
#include <stdio.h>  // 標準入出力
#include <stdlib.h> // system()を呼び出すのに必要

#define LIMIT_TIMES 7  // 回数制限の定義

/** データ型宣言 */
typedef enum Boolean { // フラグを構成する列挙
  FALSE,
  TRUE
} Boolean;

/** hangman根幹変数の宣言 */
char correctWord[256+1] = "apple";                           // 正解単語を格納する配列
int wordLength = (sizeof(correctWord) / sizeof(char)) - 1;   // 正解単語の文字列長を格納する変数
int remainCount = LIMIT_TIMES;                               // 残りの回答回数を格納する変数
char usedChar[LIMIT_TIMES+1];                                // 使われた単語を格納するための配列
char correctFlag[wordLength+1];                              // 画面に状況を表示するための文字列を格納するための配列
Boolean isCorrect = FALSE;                                   // 正誤判定をするためのフラグ
Boolean isRestart = FALSE;


/** 関数プロトタイプ宣言 */
char input();
void initialize();

/** メイン関数 */
int main(void) {  
  /** 表示用配列をハイフンで初期化 */
  int i;
  for (i = 0; i < wordLength; i++) {
	 correctFlag[i] = '-';
  }

  /** メインループ。残り回数が0になるまでまたは正解するまで繰り返す */
  do {
	 system("clear");
	 while (remainCount > 0 && isCorrect == FALSE) {
		/* 表示の処理 */
		printf("単語: ");
		for (i = 0; i < wordLength; i++) {
		  printf("%c", correctFlag[i]);
		}
		printf("\n");
		printf("使われた文字: ");
		i = 0;
		for (i = 0; i < (7 - remainCount); i++) {
		  printf("%c ", usedChar[i]);
		}
		printf("\n");
		printf("残り回数: %d\n", remainCount);
		printf("文字を入力してください: ");
		char buffer = input();
	 
		/* 英小文字以外が入力されたときは警告文を出して最初に戻る */
		if (buffer < 'a' || buffer > 'z') {
		  printf("Input invalid. Retry to input your character.\n");
		  continue;
		}

		/* 入力された文字が正解文字列に含まれていた場合、表示用配列に反映する */
		i = 0;
		while (correctWord[i] != '\0') {
		  if (correctWord[i] == buffer) {
			 correctFlag[i] = buffer;
		  }
		  i++;
		}


		/* 入力した文字がすでに入力されているかを判定。もし重複していたら最初に戻る */
		i = 0;
		Boolean isDuplicate = FALSE;
		while (usedChar[i] != '\0') {
		  if (usedChar[i] == buffer) {
			 isDuplicate = TRUE;
			 break;
		  }
		  i++;
		}
		if (isDuplicate == FALSE) {
		  usedChar[7 - remainCount] = buffer;
		  remainCount--;
		} else {
		  printf("This character already input. Try another one.\n");
		  continue;
		}

		
		/* 表示用文字列と正解文字列が一致していた場合、プログラムを終了させる。そうでなければ続行する */
		i = 0;
		Boolean isContinue = FALSE;
		while (correctFlag[i] != '\0') {
		  if (correctFlag[i] == '-') {
			 isContinue = TRUE;
		  }
		  i++;
		}
		if (isContinue == FALSE) {
		  isCorrect = TRUE;
		}
	 }
	 
	 /* 最終結果を出力する。 */
	 printf("終了！\n");
	 printf("答え：%s\n", correctWord);
	 if (isCorrect == 1) {
		printf("成功！\n");
	 } else {
		printf("失敗。。。\n");
	 }
	 char buffer = 'A';
	 while (buffer != 'y' && buffer != 'Y' && buffer != 'n' && buffer != 'N') {
		printf("続行しますか？y/n: ");
		buffer = input();
	 }
	 if (buffer == 'y' || buffer == 'Y') {
		isRestart = TRUE;
		isCorrect = FALSE;
		remainCount = LIMIT_TIMES;
	 } else {
		isRestart = FALSE;
	 }
  } while (isRestart == TRUE);
  return 0;
}

char input() {
   char buffer;
	scanf("%c", &buffer);
   scanf("%*[^\n]");
	scanf("%*c");
   printf("\n\n");
	return buffer;
}

void initialize() {
  correctWord = "apple";
  wordLength = (sizeof(correctWord) / sizeof(char)) - 1;
  remainCount = LIMIT_TIMES;
  int i;
  for (i = 0; i < LIMIT_TIMES; i++) {
	 usedChar[i] = '\0';
  }
  for (i = 0; i < WORDLENGTH)
}
