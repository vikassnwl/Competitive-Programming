# Cycle detection in graph using DFS

def checkForCycle(node, parent, vis, adj):
    vis[node] = 1
    for it in adj[node]:
        if vis[it] == 0:
            if checkForCycle(it, node, vis, adj):
                return True
        elif it != parent:
            return True
    return False

def isCycle(V, adj):
    vis = [0 for _ in range(V+1)]
    for i in range(1, V+1):
        if not vis[i]:
            if checkForCycle(i, -1, vis, adj):
                return True
    return False


V, E = map(int, input().split())

adj = [[] for _ in range(V+1)]

for _ in range(E):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)

print(isCycle(V, adj))
