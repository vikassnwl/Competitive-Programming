def findPar(u, parent):
    if u == parent[u]:
        return u
    parent[u] = findPar(parent[u], parent)
    return parent[u]

def unionn(u, v, parent, rank):
    u = findPar(u, parent)
    v = findPar(v, parent)
    if rank[u] < rank[v]:
    	parent[u] = v
    elif rank[v] < rank[u]:
    	parent[v] = u
    else:
    	parent[v] = u
    	rank[u] += 1


N, m = map(int, input().split())
edges = []
for i in range(m):
    u, v, wt = map(int, input().split())
    edges.append((u, v, wt))

edges.sort(key=lambda x: x[2])
parent = []
for i in range(N):
    parent.append(i)
rank = [0 for _ in range(N)]
	
cost = 0
mst = []
for it in edges:
    if findPar(it[1], parent) != findPar(it[0], parent):
        cost += it[2]
        mst.append((it[0], it[1]))
        unionn(it[0], it[1], parent, rank)

print(cost)
for it in mst:
    print(it[0], it[1], sep=' - ')
