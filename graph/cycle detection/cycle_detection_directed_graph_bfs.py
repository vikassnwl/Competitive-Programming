# Detecting cycle in directed graph using BFS

def isCyclic(N, adj):
    q = []
    indegree = [0 for _ in range(N+1)]
    for i in range(1, N+1):
        for it in adj[i]:
            indegree[it] += 1

    for i in range(1, N+1):
        if indegree[i] == 0:
            q.append(i)

    cnt = 0
    while q:
        node = q.pop(0)
        cnt += 1
        for it in adj[node]:
            indegree[it] -= 1
            if indegree[it] == 0:
                q.append(it)

    if cnt == N:
        return False
    return True


n, m = map(int, input().split())
adj = [[] for _ in range(n+1)]
for i in range(m):
    u, v = map(int, input().split())
    adj[u].append(v)

if isCyclic(n, adj):
    print('Yes')
else:
    print('No')
