import numpy as np
import matplotlib.pyplot as plt

def mathfunc(x):
    y = np.sqrt(-5/3 * x**2+5)
    return y

xmin = -5
xmax = 5
num = 100000
x = np.linspace(xmin, xmax, num)

y = mathfunc(x)

plt.plot(x, y)
plt.plot(x, -y)

plt.xlim(xmin, xmax)

plt.grid(True)

plt.show()
