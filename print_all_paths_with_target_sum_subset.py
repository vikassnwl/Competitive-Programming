class Pair:
    def __init__(self, i, j, psf):
        self.i = i
        self.j = j
        self.psf = psf

n = int(input())
arr = []
for _ in range(n):
    arr.append(int(input()))

tar = int(input())

dp = [[0 for _ in range(tar+1)] for _ in range(len(arr)+1)]

for i in range(len(dp)):
    for j in range(len(dp[0])):
        if j == 0:
            dp[i][j] = 1
        elif i == 0:
            dp[i][j] = 0
        else:
            if dp[i-1][j]:
                dp[i][j] = 1
            elif j >= arr[i-1]:
                if dp[i-1][j-arr[i-1]] == 1:
                    dp[i][j] = 1
print('true' if dp[-1][-1] else 'false')


queue = []
queue.append(Pair(n, tar, ''))

while len(queue) > 0:
    rem = queue.pop(0)
    if rem.i == 0 or rem.j == 0:
        print(rem.psf)
    else:
        if rem.j >= arr[rem.i-1]:
            inc = dp[rem.i-1][rem.j-arr[rem.i-1]]
            if inc:
                queue.append(Pair(rem.i-1, rem.j-arr[rem.i-1], str(rem.i-1)+' '+rem.psf))
        exc = dp[rem.i-1][rem.j]
        if exc:
            queue.append(Pair(rem.i-1, rem.j, rem.psf))
