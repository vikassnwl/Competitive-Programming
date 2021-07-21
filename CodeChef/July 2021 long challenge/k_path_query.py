# problem statement -> https://www.codechef.com/JULY21C/problems/KPATHQRY
# video tutorial -> /mnt/B238844C38841191/videos/CP

import sys
from collections import deque
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    adj = [[] for _ in range(n+1)]
    for _ in range(n-1):
        u, v = map(int, input().split())
        adj[u].append(v)
        adj[v].append(u)

    parent = [-1]*(n+1)
    level = [0]*(n+1)
    vis = [0]*(n+1)
    vis[1] = 1
    q = deque([1])

    while q:
        parentNode = q.popleft()
        for child in adj[parentNode]:
            if not vis[child]:
                vis[child] = 1
                q.append(child)
                level[child] = 1+level[parentNode]
                parent[child] = parentNode
    
    vis = [-1]*(n+1)
    for mark in range(int(input())):
        k, *queries = map(int, input().split())
        # finding deepest node
        maxDepth = 0
        nodeWithMaxDepth = 1
        for query in queries:
            if level[query] > maxDepth:
                maxDepth = level[query]
                nodeWithMaxDepth = query

        # marking all nodes between nodeWithMaxDepth and root inclusive
        vis[nodeWithMaxDepth] = mark
        while parent[nodeWithMaxDepth] != -1:
            nodeWithMaxDepth = parent[nodeWithMaxDepth]
            vis[nodeWithMaxDepth] = mark

        # finding second deepest node
        maxDepth = 0
        nodeWithMaxDepth = 1
        for query in queries:
            if vis[query] != mark and level[query] > maxDepth:
                maxDepth = level[query]
                nodeWithMaxDepth = query

        # if given nodes are already visited
        if nodeWithMaxDepth == 1:
            print('YES')
            continue

        # find the point of intersection between both the paths
        # from first deepest node to root and from second deepest node to root
        while vis[nodeWithMaxDepth] != mark:
            vis[nodeWithMaxDepth] = mark
            nodeWithMaxDepth = parent[nodeWithMaxDepth]

        # check whether any node is unvisited or present above the intersection point
        # if any of the condition is true then there is no simple path that covers the given nodes
        for query in queries:
            if vis[query] != mark or level[query] < level[nodeWithMaxDepth]:
                print('NO')
                break
        else:
            print('YES')
