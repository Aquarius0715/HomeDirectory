import numpy as np

A = np.array([[5, 4],
              [3, 2]
            ])

invA = np.linalg.inv(A)

print(invA)
