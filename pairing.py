'''
There are N cities numbered from 0 to N-1. You have to choose 2 cities such that there is no path from first city to second city .
You are given information in the form of M pairs (X,Y) i.e there is an undirected road between city X and city Y.
Find out the number of ways in which cities can be chosen.

Input Format:
The first line contains two integers, N and M separated by a single space. M lines follow. Each line contains integers separated by a single space X and Y denoting road between X and Y.

Constraints:
1 <= N <= 100000 1 <= M <= 100000 0 <= X,Y <= N-1

Output Format
An integer that denotes the number of permissible ways to choose a pair of cities.
'''

# solution using dfs
def dfs(node, vis, adj):
    global nodes_count
    nodes_count += 1
    vis[node] = 1
    for it in adj[node]:
        if not vis[it]:
            dfs(it, vis, adj)

n, m = map(int, input().split())
adj = [[] for _ in range(n)]
for _ in range(m):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)

vis = [0 for _ in range(n)]
ans = n*(n-1)//2
for i in range(n):
    if not vis[i]:
        nodes_count = 0
        dfs(i, vis, adj)
        ans -= nodes_count*(nodes_count-1)//2
print(ans)

##########################################################################################################

# solution using dsu
def findSet(i, parent):
    if parent[i] == -1:
        return i
    parent[i] = findSet(parent[i], parent)
    return parent[i]

def union_set(x, y, parent, rank):
    if x != y:
        if rank[x] < rank[y]:
            parent[x] = y
            rank[y] += rank[x]
        else:
            parent[y] = x
            rank[x] += rank[y]


def pairing():
    parent = [-1 for _ in range(n)]
    rank = [1 for _ in range(n)]
    for edge in l:
        i, j = edge
        s1 = findSet(i, parent)
        s2 = findSet(j, parent)
        union_set(s1, s2, parent, rank)

    ans = 0;
    for i in range(n):
        ans += n-rank[findSet(i, parent)]

    return ans//2

n, m = map(int, input().split())
l = []
for _ in range(m):
    u, v = map(int, input().split())
    l.append((u, v))

print(pairing())
