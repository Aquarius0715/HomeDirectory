import numpy as np

A = np.array([[2, 3, -5],
              [1, -1, 1],
              [3, -6, 2]
            ])

B = np.array([[3], [0], [-7]])

print(np.linalg.solve(A, B))
