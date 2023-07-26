import os
import random
import readchar
import time
import re

correctWord = ""
remainCount = 0
usedCharactor = []
correctAnswerStats = []

def main():

    while True:
        os.system("clear")
        
        file = open("toeic1500_utf.dat", "r")
        correctWord = random.choice(file.readlines()).split()[1]
        file.close()
        correctAnswerStats = ["-"] * len(correctWord)
        remainCount = 7
        usedCharactor = []
        isCorrect = False

        
        while (remainCount > 0):
            print("単語: " + "".join(correctAnswerStats))
            print(*usedCharactor)
            print("残り回数: " + str(remainCount))
            print("文字を入力してください: ")
            
            c = readchar.readkey()
            if c.islower() == False:
                print("Input invalid. Retry to input your character.")
                continue
            
            if c in usedCharactor:
                print("This character already input, Try another one.")
                continue;
            else:
                usedCharactor.append(c)
            
            for i, cw in enumerate(correctWord):
                if cw == c:
                    correctAnswerStats[i] = c;
                    if correctWord == correctAnswerStats:
                        isCorrect = True

            remainCount += -1


        print("終了！")
        print("答え：" + correctWord)
        if isCorrect == True:
            print("成功！")
        else:
            print("失敗...")

        print("Are you retry? [y/n]")
        c = 'a'
        while (c.casefold() != 'y' and c.casefold() != 'n'):
            c = readchar.readkey()
        if c.casefold() == 'y':
            continue
        else:
            break

    print("Bye")
                        
if __name__ == "__main__":
    main()
