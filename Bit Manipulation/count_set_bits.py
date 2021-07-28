# program to count number of set bits in an integer
# Solution 1: Using left shift bitwise operator
count = 0
for i in range(32):
    if n&(1<<i):
        count += 1

print(count)


# Brian Kernighan’s Algorithm to count set bits in an integer
# Solution 2
count = 0
while n:
    rsbm = n&-n
    n -= rsbm
    count += 1

print(count)


# Solution 3
count = 0
while n:
    n &= n-1
    count += 1

print(count)


# Solution 4: Using right shift bitwise operator
count = 0
for i in range(32):
    count += n>>i&1
return count
