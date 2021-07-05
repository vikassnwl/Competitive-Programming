import sys
input = sys.stdin.readline

# first try to make small negative numbers positive by applying one operation on each.
# then apply all remaining operation on the smallest number.

# first make all negative numbers positive, if you found 0 then apply all remaining operations on 0.
# if operations are remaining after make all negative numbers positive, then sort the numbers to find the smallest number and apply all remaining operations on that number.
# if all numbers are negative and k is greater than number then after making all numbers positive and coming out of loop, we need to apply all remaininig operations on the smallest number present in array.


# -512 2 = 512 2(making all negative numbers positive) = 512 -2(applying rest of operations in smallest number) = 510
# -2 512 = 2 512(making all negative numbers positive) = -2 512(applying rest of operations in smallest number) = 510

n, k = map(int, input().split())
arr = list(map(int, input().split()))

for i in range(n):
    if k > 0:
        if arr[i] < 0:
            arr[i] *= -1
            k -= 1
        elif arr[i] == 0:
            k = 0
        else:
            if k%2 == 1:
                arr.sort()
                arr[0] *= -1
            print(sum(arr))
            break
    else:
        print(sum(arr))
        break
else:
    if k%2 == 1:
        arr[-1] *= -1
    print(sum(arr))
