# Adjacency list undirected graph

n, m = map(int, input().split())
adj = [[] for _ in range(n+1)]
for i in range(m):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)

for row in adj:
    print(row)


# directed graph

n, m = map(int, input().split())
adj = [[] for _ in range(n+1)]
for i in range(m):
    u, v = map(int, input().split())
    adj[u].append(v)

for row in adj:
    print(row)


# weighted undirected graph

n, m = map(int, input().split())
adj = [[] for _ in range(n+1)]
for i in range(m):
    u, v, wt = map(int, input().split())
    adj[u].append([v, wt])
    adj[v].append([u, wt])

for row in adj:
    print(row)
