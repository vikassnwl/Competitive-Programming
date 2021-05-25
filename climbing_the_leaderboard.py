# Solution 1 - Linear Search
num_ranks = int(input())
ranks = list(map(int, input().split()))

num_scores = int(input())
scores = list(map(int, input().split()))

unique_ranks = sorted(set(ranks))
len_unique_ranks = len(unique_ranks)

i = 0
for score in scores:
    while i < len_unique_ranks:
        if score < unique_ranks[i]:
            break
        i += 1
    
    print(len_unique_ranks+1-i)

    
    
    
# Solution 2 - Binary Search
def climbingLeaderboard(ranked, player):
    ans = []
    unique_ranks = sorted(set(ranked))
    unique_ranks.reverse()
    
    for i in player:
        floor_idx = BS(i, unique_ranks)
        ans.append(floor_idx+1)
    
    for i in ans:
        print(i)

    
def BS(i, ranked):
        lo = 0
        hi = len(ranked)-1
        
        while lo <= hi:
            mid = lo + (hi-lo)//2
            if ranked[mid] > i:
                lo = mid+1
            else:
                hi = mid -1
                
        return lo

        
num_ranked = int(input())
ranked = list(map(int, input().split()))

num_player = int(input())
player = list(map(int, input().split()))

unique_ranked = sorted(set(ranked))
len_unique_ranked = len(unique_ranked)

climbingLeaderboard(ranked, player)
