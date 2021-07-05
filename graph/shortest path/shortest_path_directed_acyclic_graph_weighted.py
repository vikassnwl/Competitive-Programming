# Shortest path in a weighted DAG
import math

def findTopoSort(node, vis, st, adj):
    vis[node] = 1
    for it in adj[node]:
        if not vis[it[0]]:
            findTopoSort(it[0], vis, st, adj)

    st.append(node)


def shortestPath(src, N, adj):
    vis = [0 for _ in range(N)]
    st = []
    for i in range(N):
        if not vis[i]:
            findTopoSort(i, vis, st, adj)

    dist = [math.inf for _ in range(N)]
    dist[src] = 0

    while st:
        node = st.pop()
        if dist[node] != math.inf:
            for it in adj[node]:
                if dist[node]+it[1] < dist[it[0]]:
                    dist[it[0]] = dist[node]+it[1]

    for i in range(N):
        print('INF' if dist[i] == math.inf else dist[i], end= ' ')


n, m = map(int, input().split())
adj = [[] for _ in range(n)]
for i in range(m):
    u, v, wt = map(int, input().split())
    adj[u].append([v, wt])

shortestPath(0, n, adj)
