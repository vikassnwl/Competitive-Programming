# Check for bipartite graph using BFS

def bipartiteBfs(src, adj, color):
    q = []
    q.append(src)
    color[src] = 1
    while q:
        node = q.pop(0)
        for it in adj[node]:
            if color[it] == -1:
                color[it] = 1-color[node]
                q.append(it)
            elif color[it] == color[node]:
                return False
    return True


def checkBipartite(adj, n):
    color = [-1 for _ in range(n+1)]
    for i in range(n):
        if color[i] == -1:
            if not bipartiteBfs(i, adj, color):
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
