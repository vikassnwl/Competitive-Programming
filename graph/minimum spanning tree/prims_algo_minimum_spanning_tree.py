# Prim's algorithm(Brute Force)

#import math
#
#N, m = map(int, input().split())
#adj = [[] for _ in range(N)]
#for i in range(m):
#    a, b, wt = map(int, input().split())
#    adj[a].append((b, wt))
#    adj[b].append((a, wt))
#
#parent = []
#key = []
#mstSet = []
#
#for i in range(N):
#    key.append(math.inf)
#    mstSet.append(False)
#    parent.append(-1)
#
#key[0] = 0
#parent[0] = -1
#
#for count in range(N-1):
#    mini = math.inf
#
#    for v in range(N):
#        if mstSet[v] == False and key[v] < mini:
#            mini = key[v]
#            u = v
#
#    mstSet[u] = True
#
#    for it in adj[u]:
#        v, weight = it
#        if mstSet[v] == False and weight < key[v]:
#            parent[v] = u
#            key[v] = weight
#
#for i in range(1, N):
#    print(parent[i])


# Using Priority Queue

import math
from queue import PriorityQueue

N, m = map(int, input().split())
adj = [[] for _  in range(N)]

for i in range(m):
    a, b, wt = map(int, input().split())
    adj[a].append((b, wt))
    adj[b].append((a, wt))

parent = []
key = []
mstSet = []

for i in range(N):
    key.append(math.inf)
    mstSet.append(False)
    parent.append(-1)

pq = PriorityQueue()
key[0] = 0
parent[0] = -1
pq.put((0, 0))
for count in range(N-1):
    u = pq.get()[1]
    mstSet[u] = True
    for it in adj[u]:
        v, weight = it
        if mstSet[v] == False and weight < key[v]:
            parent[v] = u
            pq.put((key[v], v))
            key[v] = weight

for i in range(1, N):
    print(parent[i])
