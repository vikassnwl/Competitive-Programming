"""
We can easily find that every 6 numbers are the same. It's like {x, y, y - x,  - x,  - y, x - y, x, y, y - x, ...}.
"""

arr = list(map(int, input().split()))
n = int(input())
 
for i in range(2, 6):
    arr.append(arr[i-1]-arr[i-2])
 
print(arr[n%6-1]%(10**9+7))
