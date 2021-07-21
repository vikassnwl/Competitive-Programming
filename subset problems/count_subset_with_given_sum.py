def ss(a, sum, n):
    if n==0:
        if sum==0:
            return 1
        else:
            return 0
    if a[n-1]>sum:
        return ss(a, sum, n-1)
    return ss(a,sum,n-1) + ss(a,sum-a[n-1],n-1)

arr = [0, 0, 1]
len_arr = len(arr)
target = 1
print(ss(arr, target, len_arr))


######################################

def subsets(nums, target):
    def solve(arr, n, i, subarr):
        nonlocal count
        if i == n:
            if target == sum(subarr):
                count += 1
            return
        solve(arr, n, i+1, subarr+[arr[i]])
        solve(arr, n, i+1, subarr)
    
    i = 0; subarr = []; count = 0
    solve(nums, len(nums), 0, [])
    return count

print(subsets([0, 0, 1], 1))

