def find_parent(i, parent):
    if parent[i] == -1:
        return i
    parent[i] = find_parent(parent[i], parent)
    return parent[i]

def union(x, y, parent, rank):
    if rank[x] < rank[y]:
        parent[x] = y
        rank[y] += rank[x]
    else:
        parent[y] = x
        rank[x] += rank[y]

n, m = map(int, input().split())
edge_list = []
for _ in range(m):
    u, v, wt = map(int, input().split())
    edge_list.append((u, v, wt))

edge_list.sort(key=lambda x: x[2])

cost = 0
mst = []
parent = [-1 for _ in range(n+1)]
rank = [1 for _ in range(n+1)]
for edge in edge_list:
    u, v, wt = edge

    s1 = find_parent(u, parent)
    s2 = find_parent(v, parent)

    if s1 != s2:
        cost += wt
        mst.append((u, v))
        union(s1, s2, parent, rank)


print(cost)
for it in mst:
    print(it[0], it[1], sep=' - ')
