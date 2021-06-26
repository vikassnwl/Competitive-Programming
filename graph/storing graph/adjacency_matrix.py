# storing graph in adjacency matrix

n, m = map(int, input().split())

# declare the adjacency matrix
adj = [[0 for _ in range(n+1)] for _ in range(n+1)]

# take edges as input
for i in range(m):
    u, v = map(int, input().split())
    adj[u][v] = 1
    adj[v][u] = 1

# printing adjacency matrix
for row in adj:
    print(*row)
