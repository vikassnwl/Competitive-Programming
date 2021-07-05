import sys
input = sys.stdin.readline

n, s, t = map(int, input().split())
pos = list(map(int, input().split()))

count = 0
seen = set()
while s != t:
    if s not in seen:
        seen.add(s)
    else:
        print(-1)
        break
    count += 1
    s = pos[s-1]
else:
    print(count)
