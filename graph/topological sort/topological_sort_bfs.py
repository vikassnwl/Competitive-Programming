# Topological Sort using BFS

def topoSort(N, adj):
    q = []
    indegree = [0 for _  in range(N)]
    for i in range(N):
        for it in adj[i]:
            indegree[it] += 1

    for i in range(N):
        if indegree[i] == 0:
            q.append(i)

    topo = []
    while q:
        node = q.pop(0)
        topo.append(node)
        for it in adj[node]:
            indegree[it] -= 1
            if indegree[it] == 0:
                q.append(it)

    return topo



n, m = map(int, input().split())
adj = [[] for _ in range(n)]
for i in range(m):
    u, v = map(int, input().split())
    adj[u].append(v)

for x in topoSort(n, adj):
    print(x)
