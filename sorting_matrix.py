matrix = [[4, 3], [4, 2], [5, 1]]


# sorting in descendig order by first item of subarray and ascending order by second item of subarray
matrix.sort(key=lambda x: (-x[0], x[1]))
print(matrix)
