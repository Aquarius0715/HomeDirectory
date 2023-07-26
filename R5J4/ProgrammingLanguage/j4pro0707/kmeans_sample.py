# 2次元プロットデータ（3クラス）のデータを読み込んで，k-means法でクラスタリングする
import numpy as np
import random as rnd

# 2点間距離を測る関数
def distance(a, b):
    dist = 0.0
    for i in range(len(a)):
        dist += (a[i] - b[i])**2
    dist = np.sqrt(dist)    
    return dist

# データを読み込む
data = np.loadtxt("data.csv", delimiter=",")

G = []
for i in range(0, 3):
    x = rnd.random()
    y = rnd.random()
    G.append(np.array([x, y]))

Gtemp = []
while (Gtemp != G):
    for i in range(0, len(data)):
        for j in range(0, len(G)):
            dist = distance(G[j], data[i])
            for k in range(0, len(G)):
                if (dist > distance(G[k], data[i])):
                    dist = distance(G[k], data[i])
print(G)
    
val1 = np.array([2,3])
dist = distance(val1, data[0])
print(dist)

val2 = np.array([-2,0])
dist = distance(val2, data[0])
print(dist)

val3 = np.array([3,4])
dist = distance(val3, data[0])
print(dist)
