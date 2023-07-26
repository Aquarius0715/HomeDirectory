import numpy as np
import matplotlib.pyplot as plt
import csv

###############
# グラフ表示したい関数
###############
def mathfunc(x):
    y = 1.21 * x - 1.89
    return y

#######################
# 作成した関数のグラフを表示する
#######################

# 定義域を設定
xmin = -2.0
xmax = 16.0
num = 200 # xminからxmaxまでをnum個で区切る
x = np.linspace(xmin, xmax, num)

# 関数から値域を取得
y = mathfunc(x)

# 点どうしを直線でつなぐ
plt.plot(x, y, color='red')

plt.plot(x, y)

# 適切な表示範囲を指定
plt.xlim(xmin, xmax)

# グリッド追加
plt.grid(True)


with open("data.csv") as f:
    reader = csv.reader(f)
    for row in reader:
        x = float(row[0])
        y = float(row[1])
        if mathfunc(x) > y:
            plt.plot(x, y, ".", color="green")
        else:
            plt.plot(x, y, ".", color="red")

# 表示
plt.show()
