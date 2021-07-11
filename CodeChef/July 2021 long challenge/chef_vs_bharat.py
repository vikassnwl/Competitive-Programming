# problem link -> https://www.codechef.com/JULY21C/problems/CHEFORA/
# video tutorial -> /mnt/B238844C38841191/videos/CP

s, lookup = 0, [0]
for i in range(1, 100001):
    s += int(str(i)[:-1]+str(i)[::-1])
    lookup.append(s)
    
query = int(input())
for q in range(query):
    l, r = map(int, input().split())
    print(pow((lookup[l]-lookup[l-1]), (lookup[r]-lookup[l]), 1000000007))

