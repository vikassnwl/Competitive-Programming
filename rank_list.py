n, k = map(int, input().split())
matrix = []
for _ in range(n):
    matrix.append(list(map(int, input().split())))

matrix.sort(key=lambda x: (-x[0], x[1]))

print(matrix.count(matrix[k-1]))
