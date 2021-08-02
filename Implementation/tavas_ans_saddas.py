#Video tutorial at -> /mnt/B238844C38841191/Ubuntu Stuff/Competitive Programming
import sys
input = sys.stdin.readline

n = input().rstrip()
digits = len(n)

ans = 2**digits-2

for i in range(digits):
    if n[i] == '7':
        ans += 2**(digits-1-i)

print(ans+1)
