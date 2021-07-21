# bridges in graph

def dfs(node, parent, vis, tin, low, timer, adj):
    vis[node] = 1
    timer += 1
    tin[node], low[node] = timer, timer
    for it in adj[node]:
        if it == parent:
            continue
        if not vis[it]:
            dfs(it, node, vis, tin, low, timer, adj)
            low[node] = min(low[node], low[it]);
            if low[it] > tin[node]:
                print(node, it)
        else:
            # if already visited and not a parent, that means it's a back edge.
            low[node] = min(low[node], tin[it])

n, m = map(int, input().split())
adj = [[] for _ in range(n+1)]
for _ in range(m):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)

tin = [-1]*(n+1)
low = [-1]*(n+1)
vis = [0]*(n+1)
timer = 0
for i in range(1, n+1):
    if not vis[i]:
        dfs(i, -1, vis, tin, low, timer, adj)

