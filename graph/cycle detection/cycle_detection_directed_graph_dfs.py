# Check cycle in graph using DFS

def checkCycle(node, adj, vis, dfsVis):
    vis[node] = 1
    dfsVis[node] = 1
    for it in adj[node]:
        if not vis[it]:
            if checkCycle(it, adj, vis, dfsVis):
                return True
        elif dfsVis[it]:
            return True

    dfsVis[node] = 0
    return False


def isCyclic(N, adj):
    vis = [0 for _ in range(N+1)]
    dfsVis = [0 for _ in range(N+1)]
    for i in range(1, N+1):
        if not vis[i]:
            if checkCycle(i, adj, vis, dfsVis):
                return True

    return False


n, m = map(int, input().split())
adj = [[] for _ in range(n+1)]
for i in range(m):
    u, v = map(int, input().split())
    adj[u].append(v)

if isCyclic(n, adj):
    print('Yes')
else:
    print('No')
