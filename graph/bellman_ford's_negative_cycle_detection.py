import math

n, m = map(int, input().split())
edges = []
for _ in range(m):
    u, v, wt = map(int, input().split())
    edges.append((u, v, wt))

src = int(input())
inf = math.inf
dist = [inf]*n
dist[src] = 0

for i in range(1, n):
    for it in edges:
        u, v, wt = it
        if dist[u]+wt<dist[v]:
            dist[v] = dist[u]+wt

for it in edges:
    u, v, wt = it
    if dist[u]+wt < dist[v]:
        print('Negative Cycle')
        break
else:
    for i in range(n):
        print(i, dist[i])

