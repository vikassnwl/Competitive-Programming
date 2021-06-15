n, k = map(int, input().split())

"""
        ============================================
        This problem will be solved using AP Formula
        ============================================


n = 10
1 3 5 7 9 | 2 4 6 8 10

Processing left half:
    a1 = 1
    d = 2
    ak = a1+(k-1)d
    find 3rd term, k=3
    a3 = 1+(3-1)*2 = 5

Processing right half:
    if we have to find the 6th number then we have to make it 1 because the 6th number is at position 1 in right half.
    We have to subtract the length of left half from the position we have to find number at.
    6-5 = 1
    k = 6
    k = k-(n+1)//2 = 1
    a1 = 2
    d = 2
    ak = a1+(k-1)d
    a1 = 2+(0)*2 = 2
"""

if k <= (n+1)//2: #k lies in left half
    print(1+(k-1)*2)
else: #k lies in right half
    print(2+(k-(n+1)//2-1)*2)
