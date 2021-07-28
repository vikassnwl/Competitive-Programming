arr = list(map(int, input().split()))
n = len(arr)

import math

max_ = -math.inf
sum_ = 0

for i in range(n):
    sum_ += arr[i]
    if sum_ > max_:
        max_ = sum_
    if sum_ < 0:
        sum_ = 0

print(max_)
