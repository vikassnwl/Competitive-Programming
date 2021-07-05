# method 1 using bfs
n, m = map(int, input().split())
adj = [[] for _ in range(n+m+1)]
x = 0
for i in range(1, n+1):
    xx, *yy = map(int, input().split())
    x += xx
    for y in yy:
        adj[i].append(y+n)
        adj[y+n].append(i)

if x == 0:
    print(n)
else:
    vis = [0 for _ in range(n+m+1)]
    count = 0
    for i in range(1, n+1):
        if not vis[i]:
            count += 1
            vis[i] = 1
            queue = []
            queue.append(i)

            while queue:
                node = queue.pop(0)
                for it in adj[node]:
                    if not vis[it]:
                        vis[it] = 1
                        queue.append(it)
    print(count-1)


# method 2 using dfs
n, m = map(int, input().split())
adj = [[] for _ in range(n+m+1)]
x = 0
for i in range(1, n+1):
    xx, *yy = map(int, input().split())
    x += xx
    for y in yy:
        adj[i].append(y+n)
        adj[y+n].append(i)

if x == 0:
    print(n)
else:
    def dfs(node, adj, vis):
        vis[node] = 1
        for it in adj[node]:
            if not vis[it]:
                dfs(it, adj, vis)

    vis = [0 for _ in range(n+m+1)]
    count = 0
    for i in range(1, n+1):
        if not vis[i]:
            count += 1
            dfs(i, adj, vis)
    print(count-1)
