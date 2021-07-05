# Dijkstra's algorithm

from queue import PriorityQueue
import math

n, m = map(int, input().split())
g = [[] for _ in range(n+1)] # 1-indexed adjacency list for graph

for i in range(m):
    a, b, wt = map(int, input().split())
    g[a].append((b, wt))
    g[b].append((a, wt))

source = int(input())

# Dijkstra's algorithm begins from here
pq = PriorityQueue() # min-heap; In pair => (dist, from)
distTo = [math.inf for _ in range(n+1)] # 1-indexed array for calculating shortest paths;
distTo[source] = 0
pq.put((0, source)) # (dist, from)

while pq.qsize():
    dist, prev = pq.get()
    for it in g[prev]:
        nxt, nxtDist = it
        if distTo[nxt] > dist+nxtDist:
            distTo[nxt] = dist+nxtDist
            pq.put((distTo[nxt], nxt))

for i in range(1, n+1):
    print(distTo[i], end=' ')
