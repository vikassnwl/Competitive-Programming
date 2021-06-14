# print all prime numbers till n

n = int(input())

arr = [0 for _ in range(n+1)]

for i in range(2, int(n**.5)+1):
    for j in range(i*i, n+1, i):
        if arr[j] == 0:
            arr[j] = 1

for i in range(2, n+1):
    if arr[i] == 0:
        print(i)
