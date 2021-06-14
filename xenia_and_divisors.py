"""
In this problem you should guess that exists only three valid groups of three

1) 1, 2, 4

2) 1, 2, 6

3) 1, 3, 6

(You can see that integers 5 and 7 are bad).

So, we will greedy take these groups of three. If some integers will be not used, the answer is -1. In other case, print found answer.
"""

n = int(input())
arr = list(map(int, input().split()))
 
from collections import Counter
 
c = Counter(arr)
 
if 5 in arr or 7 in arr or arr.count(1) != n//3 or arr.count(2)+arr.count(3) != n//3 or (3 in arr and arr.count(3) > arr.count(6)):
    print(-1)
else:
    for i in range(n//3):
        print(1, end=' ')
        if c[2] > 0:
            print(2, end=' ')
            c[2] -= 1
            if c[4] > 0:
                print(4)
                c[4] -= 1
            else:
                print(6)
        else:
            print(3, end=' ')
            print(6)
