import sys
input = sys.stdin.readline

n, m = map(int, input().split())
arr = list(map(int, input().split()))

sum = 0
for _ in range(m):
    u, v = map(int, input().split())
    sum += min(arr[u-1], arr[v-1])

print(sum)
