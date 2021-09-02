n = int(input())
arr = list(map(int, input().split()))

mp = {}
for i in range(n):
    mp[arr[i]] = i

cnt = 0
for i in range(1, n+1):
    if i!=arr[i-1]:
        cnt += 1
        mp[arr[i-1]] = mp[i]
        arr[i-1], arr[mp[i]] = arr[mp[i]], arr[i-1]

print(cnt)
