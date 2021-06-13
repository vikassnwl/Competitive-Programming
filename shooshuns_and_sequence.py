"""
Note that the k-th element is copied to the end.
Then the (k+1)-th element from the initial sequence is copied, then (k+2)-th, … , n-th, k-th, (k+1)-th, etc.
So all the numbers on the blackboard will become equal if and only if all the numbers from the k-th to the n-th in the initial sequence were equal.
It's now also obvious that the number of operations needed for it is equal to the index of the last number that is not equal to the n-th element of the initial sequence, because it's exactly the number of deletions needed to eliminate the elements that are not equal to the last one.
If this number is greater than k, then answer is -1. Complexity — O(n).
"""
n, k = map(int, input().split())
arr = list(map(int, input().split()))
 
last_num = arr[-1]
idx = -1
 
for i in range(n-1):
    if arr[i] != last_num:
        idx = i
 
 
if idx+1 >= k:
    print(-1)
else:
    print(idx+1)
