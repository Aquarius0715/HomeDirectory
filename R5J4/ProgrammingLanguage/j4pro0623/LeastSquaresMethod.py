# 各ライブラリのインポート
import numpy as np
import matplotlib.pyplot as plt
import csv
import sys
import math

# 各データを格納しておくための配列を宣言
x = []
y = []
t = []

# CSVファイルからデータをロードしてくる処理
if len(sys.argv) != 2:
    sys.exit("usage: python3 LeastSquaresMethod.py <filename>")
with open(sys.argv[1], encoding='utf8', newline='') as f:
    csvreader = csv.reader(f)
    for row in csvreader:
        x.append(float(row[0]))
        y.append(float(row[1]))
        t.append(1)

# ロードしてきたデータからnumpyの配列を作成
X = np.array(x)
Y = np.array(y)
T = np.array(t)

# 作成した配列から各行列とベクトルと求める
A = np.array([
    [np.sum(X**8), np.sum(X**7), np.sum(X**6), np.sum(X**5), np.sum(X**4)],
    [np.sum(X**7), np.sum(X**6), np.sum(X**5), np.sum(X**4), np.sum(X**3)],
    [np.sum(X**6), np.sum(X**5), np.sum(X**4), np.sum(X**3), np.sum(X**2)],
    [np.sum(X**5), np.sum(X**4), np.sum(X**3), np.sum(X**2), np.sum(X**1)],
    [np.sum(X**4), np.sum(X**3), np.sum(X**2), np.sum(X**1), len(x)]
])
B = np.array([
    [np.sum(X**4*Y)],
    [np.sum(X**3*Y)],
    [np.sum(X**2*Y)],
    [np.sum(X**1*Y)],
    [np.sum(Y)]
])

# 計算するためにA行列の逆行列を求める
Ainv = np.linalg.inv(A)

# 各行列とベクトルとドット積を求める
Ans = np.dot(Ainv, B)

# 直線の方程式関数
def func(x) -> float:
    if len(Ans) == 2:
        y = Ans[0] * x + Ans[1]
        return y
    elif len(Ans) == 3:
        y = np.power(x, 2) * Ans[0] + Ans[1] * x + Ans[2]
        return y
    elif len(Ans) == 4:
        y = np.power(x, 3) * Ans[0] + np.power(x, 2) * Ans[1] + np.power(x, 1) * Ans[2] + Ans[3]
        return y
    elif len(Ans) == 5:
        y = np.power(x, 4) * Ans[0] + np.power(x, 3) * Ans[1] + np.power(x, 2) * Ans[2] + np.power(x, 1) * Ans[3] + Ans[4]
        return y
    else:
        print("Error")
        exit(1)
    
def solveRMSE(x, y) -> float:
    rmse = 0
    for x1, y1 in zip(x, y):
        rmse += pow(func(x1) - float(y1), 2)
    rmse /= len(x)
    rmse = np.sqrt(rmse)
    return rmse

# パラメータの表示
print(Ans)
print("rmse=" + str(solveRMSE(x, y)))

# パラメータを関数に代入しグラフを出力する
plt.plot(x, func(x))
plt.scatter(x, y)
plt.show()
