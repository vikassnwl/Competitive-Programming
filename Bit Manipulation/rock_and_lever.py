import sys
input = sys.stdin.readline

def lsb_pos(n):
    return len(f'{n:b}')-1

for _ in range(int(input())):
    n = int(input())

    lsb_freq = [0]*32
    # increment the index where index is position of leftmost set bit

    arr = list(map(int, input().split()))
    
    for num in arr:
        pos_lsb = lsb_pos(num)
        lsb_freq[pos_lsb] += 1
    
    ans = 0
    for f in lsb_freq:
        ans += (f-1)*f//2
    print(ans)

