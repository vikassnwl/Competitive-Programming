import math
 
def gcd(x, y):
    if(y == 0):
        return x
    else:
        return gcd(y,x%y)
 
n = int(input())
ans = 0
m = int(math.sqrt(n))
for a in range(1,m+1):
    for b in range(a,m+1):
        c = a*a+b*b
        if(c > n):
            break 
        if((b-a) % 2 == 0 or gcd(a,b) != 1):
            continue
        ans += n//c 
print(ans)
