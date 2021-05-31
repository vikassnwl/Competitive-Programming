for _ in range(int(input())):
    N = int(input())
    A = list(map(int, input().split()))
    i = 0
    while i < N:
        j = i
        while j < N-1:
            if A[j]*A[j+1] > 0:
                break
            j += 1
        k = j-i+1
        for l in range(i, j+1):
            A[l] = k
            k -= 1
        i = j+1
    print(*A)
