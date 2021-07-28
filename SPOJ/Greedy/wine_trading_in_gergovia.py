import sys
input = sys.stdin.readline

while True:
    n = int(input())
    if n == 0:
        break
    arr = list(map(int, input().split()))

    i = 0
    j = 0
    ans = 0
    while i<n and j<n:
        if arr[i] > 0 and arr[j] > 0:
            j += 1
        elif arr[i] < 0 and arr[j] < 0:
            i += 1
        else:
            ans += abs(i-j)*min(arr[i], abs(arr[j]))
            temp = arr[i]
            arr[i] -= min(arr[i], abs(arr[j]))
            arr[j] += min(temp, abs(arr[j]))
            if arr[i] == 0:
                i += 1
            if arr[j] == 0:
                j += 1
    print(ans)


