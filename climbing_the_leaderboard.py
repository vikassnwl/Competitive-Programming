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
