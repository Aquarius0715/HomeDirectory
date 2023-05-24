import numpy as np
import matplotlib.pyplot as plt

###############
# グラフ表示したい関数
###############
def mathfunc(x):
    y = x**4 - 8*x**3 + 18*x**2 - 3*x + 1
    return y

def mathfunc2(x):
    y = 10*x + 5
    return y


#######################
# 作成した関数のグラフを表示する
#######################

# 定義域を設定
xmin = -2.0
xmax = 3.5
num = 200 # xminからxmaxまでをnum個で区切る
x = np.linspace(xmin, xmax, num)

# 関数から値域を取得
y = mathfunc(x)

# 点どうしを直線でつなぐ
plt.plot(x, y, color='red')

y = mathfunc2(x)

plt.plot(x, y)

# 適切な表示範囲を指定
plt.xlim(xmin, xmax)

# グリッド追加
plt.grid(True)

# 表示
plt.show()
