n = int(input())
arr = list(map(int, input().split()))
 
arr.sort()
 
arr[0], arr[-1] = arr[-1], arr[0]
 
print(*arr)
