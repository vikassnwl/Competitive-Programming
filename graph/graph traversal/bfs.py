def bfsOfGraph(V: int, adj: list) -> list:
    bfs = []
    vis = [0 for _ in range(V+1)]
    for i in range(1, V+1):
        if not vis[i]:
            q = []
            q.append(i)
            vis[i] = 1
            while q:
                node = q.pop(0)
                bfs.append(node)

                for it in adj[node]:
                    if not vis[it]:
                        q.append(it)
                        vis[it] = 1
    return bfs
