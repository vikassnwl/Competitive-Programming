# Topological Sort DFS

def findTopoSort(node, vis, st, adj):
    vis[node] = 1
    for it in adj[node]:
        if not vis[it]:
            findTopoSort(it, vis, st, adj)

    st.append(node)


def topoSort(N, adj):
    st = []
    vis = [0 for _ in range(N)]
    for i in range(N):
        if vis[i] == 0:
            findTopoSort(i, vis, st, adj)

    topo = []
    while st:
        topo.append(st.pop())

    return topo


n, m = map(int, input().split())
adj = [[] for _ in range(n)]
for i in range(m):
    u, v = map(int, input().split())
    adj[u].append(v)

for x in topoSort(n, adj):
    print(x)
