arr = [5, 9, 7, 6]
ans = 0
for i in range(32):
    cnt_zero = 0
    cnt_one = 0
    for num in arr:
        if num&1<<i:
            cnt_one += 1
        else:
            cnt_zero += 1
    ans += cnt_zero*cnt_one*1<<i
print(ans)

