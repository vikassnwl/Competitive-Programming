#Video tutorial at -> /mnt/B238844C38841191/Ubuntu Stuff/Competitive Programming
#Problem link -> https://cses.fi/problemset/task/1092
import sys
input = sys.stdin.readline
 
n = int(input())
 
s1 = set()
s2 = set()
 
if n%2 == 0:
    if (n//2)%2 == 0:
        print('YES')
        flag = True
        for i in range(1, n//2+1):
            if flag:
                s1.update((i, n+1-i))
                flag = not flag
            else:
                s2.update((i, n+1-i))
                flag = not flag
        print(len(s1))
        print(*s1)
        print(len(s2))
        print(*s2)
    else:
        print('NO')
else:
    if ((n-1)//2)%2 == 1:
        print('YES')
        s2.add(n)
        flag = True
        for i in range(1, n//2+1):
            if flag:
                s1.update((i, n-i))
                flag = not flag
            else:
                s2.update((i, n-i))
                flag = not flag
        print(len(s1))
        print(*s1)
        print(len(s2))
        print(*s2)
    else:
        print('NO')
