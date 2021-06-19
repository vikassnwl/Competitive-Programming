n = int(input())
arr = list(map(int, input().split()))

ans = 0

for i in range(32):
    set_bits = 0
    for j in range(n):
        if arr[j]&(1<<i):
            set_bits += 1
    ans += set_bits*(set_bits-1)/2

print(int(ans))
