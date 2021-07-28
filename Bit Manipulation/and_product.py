import sys
input = sys.stdin.readline

for _ in range(int(input())):
    l, r = map(int, input().split())
    d = r-l
    ans = 0
    for i in range(32):
        if d < 1<<i:
            ans += (l>>i&1&r>>i&1)*1<<i
    print(ans)
