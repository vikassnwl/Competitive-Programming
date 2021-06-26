# Cycle detection in undirected graph using bfs

def checkForCycle(s, V, adj, visited):
    # Create a queue for BFS
    q = []
    visited[s] = True
    q.append([s, -1])

    while q:
        node, par = q.pop(0)

        for it in adj[node]:
            if not visited[it]:
                visited[it] = True
                q.append([it, node])
            elif par != it:
                return True
    return False


def isCycle(V, adj):
    vis = [0 for _ in range(V+1)]
    for i in range(1, V+1):
        if not vis[i]:
            if checkForCycle(i, V, adj, vis):
                return True
    return False


V = 11
adj = [[], [2], [1, 4], [5], [2], [3, 10, 6], [5, 7], [6, 8], [7, 9, 11], [10, 8], [5, 9], [8]]

print(isCycle(V, adj))
