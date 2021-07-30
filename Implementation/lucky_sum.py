import sys
input = sys.stdin.readline

lucky_arr = [4, 7]
p = 0
for i in range(1, 9):
    j = 2**i
    while j:
        lucky_arr += [lucky_arr[p]*10+4]
        lucky_arr += [lucky_arr[p]*10+7]
        p += 1
        j -= 1

lucky_arr += [4444444444]

l, r = map(int, input().split())

for i in range(len(lucky_arr)):
    if lucky_arr[i] >= l:
        break

ans = 0
while lucky_arr[i] <= r:
    ans += (lucky_arr[i]-l+1)*lucky_arr[i]
    l = lucky_arr[i]+1
    i += 1

print(ans+(r-l+1)*lucky_arr[i])
