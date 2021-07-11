'''
Shobita is planning for a reunion with her friends. She is very much excited and making all the preparations. She is busy selecting the restaurants and other points for fun and activities. She has selected N such points. There are R restaurants she has selected considering the amount of time they might have. Shobita wants to enjoy it to the maximum extent with her friends and for that, she needs to plan well. She knows the points (U, V) which are directly connected by a road and the travel time T units required to cover the distance between them. There are E roads between these N points.



Note: U is not equal to V.


She wants to know the minimum time she will have to spend to reach the nearest restaurant from all the N points so that she can plan accordingly and know what to do with the amount of time she and her friends will have. She is busy with all other preparations and needs your help in calculating the time required. Can you help her?



Input Format
The first line of input consists of two space-separated integers, N and E respectively.

Next E lines each consists of three space-separated integers, U, V and T.

The next line consists of a single integer denoting the number of Restaurants points, R


The next line consists of R space-separated integers denoting the points where Restaurants are located.



Constraints
1<= N <=100000
0<= E <=100000

0<= T <=100000

1<= U, V <=N

1<= R <=N



Output Format
Print the N lines with each line denoting the minimum time required to reach the nearest restaurant from that point.

Sample TestCase 1
Input
3 2
1 2 6
2 3 4
1
3
Output
10
4
0
'''

# shortest distance between src and other nodes in weighted undirected graph BFS
import math

def BFS(src, N, adj):
    dist = [math.inf for _ in range(N+1)]
    q = []
    q.append(src)
    dist[src] = 0
    while q:
        node = q.pop(0)
        for it, wt in adj[node]:
            if dist[node]+wt < dist[it]:
                dist[it] = dist[node]+wt
                q.append(it)

    return dist


N, E = map(int, input().split())
adj = [[] for _ in range(N+1)]

for _ in range(E):
    U, V, T = map(int, input().split())
    adj[U].append((V, T))
    adj[V].append((U, T))

R = int(input())
R_arr = list(map(int, input().split()))

for i in range(1, N+1):
    min_dist = math.inf
    dist = BFS(i, N, adj)
    for r in R_arr:
        min_dist = min(min_dist, dist[r])

    print(min_dist)

