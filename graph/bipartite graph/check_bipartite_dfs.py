# Check for bipartite graph using DFS

def bipartiteDfs(node, adj, color):
    if color[node] == -1:
        color[node] = 1

    for it in adj[node]:
        if color[it] == -1:
            color[it] = 1-color[node]
            if not bipartiteDfs(it, adj, color):
                return False
        elif color[it] == color[node]:
            return False
    
    return True


def checkBipartite(adj, n):
    color = [-1 for _ in range(n+1)]
    for i in range(n):
        if color[i] == -1:
            if not bipartiteDfs(i, adj, color):
                return False

    return True



n, m = map(int, input().split())
adj = [[] for _ in range(n+1)]
for i in range(m):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)

if checkBipartite(adj, n):
    print('Yes')
else:
    print('No')
