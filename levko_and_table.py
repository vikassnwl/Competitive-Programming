"""
Matrix,in which all diagonal elements equal k and other elements equal 0, satisfied all conditions.

For example, if n = 4 and k = 7, our matrix will be

7 0 0 0

0 7 0 0

0 0 7 0

0 0 0 7
"""
n, k = map(int, input().split())

matrix = [[0 for _ in range(n)] for _ in range(n)]

for i, row in enumerate(matrix):
    row[i] = k
    print(*row)
