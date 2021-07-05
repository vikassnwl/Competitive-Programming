#https://www.codechef.com/JULY21C/problems/XXOORR
#Video tutorial available at /mnt/B238844C38841191/videos/CP

import sys
import math
input = sys.stdin.readline

for _ in range(int(input())):
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))

    ans = 0

    for i in range(32):
        set_bits = 0
        for j in range(n):
            if arr[j]&(1<<i):
                set_bits += 1
        ans += math.ceil(set_bits/k)

    print(ans)
