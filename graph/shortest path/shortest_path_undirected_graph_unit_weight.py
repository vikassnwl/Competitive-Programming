#Shortest distance in undirected graph
import math

def BFS(adj, N, src):
    dist = [math.inf for _ in range(N)]
    q = []
    dist[src] = 0
    q.append(src)

    while q:
        node = q.pop(0)
        for it in adj[node]:
            if dist[node]+1 < dist[it]:
                dist[it] = dist[node]+1
                q.append(it)

    for i in range(N):
        print(dist[i], end=' ')


n, m = map(int, input().split())
adj = [[] for _ in range(n)]
for i in range(m):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)

BFS(adj, n, 0)
