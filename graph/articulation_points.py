# bridges in graph

def dfs(node, parent):
    global timer
    vis[node] = 1
    timer += 1
    tin[node], low[node] = timer, timer
    child = 0
    for it in adj[node]:
        if it == parent:
            continue
        if not vis[it]:
            dfs(it, node)
            low[node] = min(low[node], low[it]);
            if low[it] >= tin[node] and parent != -1:
                print(node)
            child += 1
        else:
            # if already visited and not a parent, that means it's a back edge.
            low[node] = min(low[node], tin[it])
    
    if parent == -1 and child > 1:
        print(1)

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

dfs(1, -1)

