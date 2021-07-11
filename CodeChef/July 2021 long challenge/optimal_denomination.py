# problem link -> https://www.codechef.com/JULY21C/problems/MINNOTES
# video tutorial -> /mnt/B238844C38841191/videos/CP

import sys
input = sys.stdin.readline

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a%b)

for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))

    if n == 1:
        print(1)
        continue

    forward_gcd = [0]*n
    backward_gcd = [0]*n

    forward_gcd[0] = arr[0]
    backward_gcd[-1] = arr[-1]

    for i in range(1, n):
        forward_gcd[i] = gcd(arr[i], forward_gcd[i-1])

    for i in range(n-2, -1, -1):
        backward_gcd[i] = gcd(arr[i], backward_gcd[i+1])

    lookup = [0]*n
    lookup[0] = backward_gcd[1]
    lookup[-1] = forward_gcd[-2]

    for i in range(1, n-1):
        lookup[i] = gcd(forward_gcd[i-1], backward_gcd[i+1])

    sum_arr = sum(arr)
    min_sum = sys.maxsize

    for i in range(n):
        min_sum = min(min_sum, (sum_arr-arr[i])//lookup[i]+1)

    print(min_sum)
