def dfs(node, st, vis, adj):
    vis[node] = 1
    for it in adj[node]:
        if not vis[it]:
            dfs(it, st, vis, adj)
    st.append(node)

def revDfs(node, vis, transpose):
    print(node, end=' ')
    vis[node] = 1
    for it in transpose[node]:
        if not vis[it]:
            revDfs(it, vis, transpose)

n, m = map(int, input().split())
adj = [[] for _ in range(n+1)]
for _ in range(m):
    u, v = map(int, input().split())
    adj[u].append(v)

st = []
vis = [0]*(n+1)
for i in range(1, n+1):
    if not vis[i]:
        dfs(i, st, vis, adj)

transpose = [[] for _ in range(n+1)]
for i in range(1, n+1):
    vis[i] = 0
    for it in adj[i]:
        transpose[it].append(i)

while st:
    node = st.pop()
    if not vis[node]:
        print('SCC:', end=' ')
        revDfs(node, vis, transpose)
        print()

