import sys
input = sys.stdin.readline

arr = []
n = int(input())
for _ in range(n):
    arr.append(int(input()))

for mask in range(1<<n):
    tot = 0
    for i in range(n):
        if mask>>i&1:
            tot += arr[i]
        else:
            tot -= arr[i]
    if tot%360 == 0:
        print('YES')
        break
else:
    print('NO')
