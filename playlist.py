n = int(input())
k = list(map(int, input().split()))

j = 0
max_len = 1
dict = {}

for i in range(n):
    if k[i] in dict and j <= dict[k[i]]:
        max_len = max(max_len, i-j)
        j = dict[k[i]]+1
    dict[k[i]] = i

max_len = max(max_len, i+1-j)

print(max_len)
