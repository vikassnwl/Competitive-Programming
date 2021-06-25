# Adjacency list

n, m = map(int, input().split())
adj = [[] for _ in range(n+1)]
for i in range(m):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)

for row in adj:
    print(row)
