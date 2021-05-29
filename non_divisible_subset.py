n, k = map(int, input().split())
S = list(map(int, input().split()))

mod_freq = [0]*k

for num in S:
    mod_freq[num%k] += 1
    
len_subset = 0

if mod_freq[0] > 0:
    len_subset += 1
    
if k%2 == 0 and mod_freq[k//2] > 0:
    len_subset += 1
    
for i in range(1, (k+1)//2):
    len_subset += max(mod_freq[i], mod_freq[k-i])
    
print(len_subset)
