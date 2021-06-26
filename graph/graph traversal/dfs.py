# Depth First Traversal in Graph

def dfs(node, vis, adj, storeDfs):
    storeDfs.append(node)
    vis[node] = 1
    for it in adj[node]:
        if not vis[it]:
            dfs(it, vis, adj, storeDfs)

def dfsOfGraph(V, adj):
    storeDfs = []
    vis = [0 for _ in range(V+1)]
    for i in range(1, V+1):
        if not vis[i]:
            dfs(i, vis, adj, storeDfs)
    return storeDfs


V = 7
adj = [[], [2], [1, 4, 7], [5], [2, 6], [3], [4, 7], [2, 6]]

print(dfsOfGraph(V, adj))
