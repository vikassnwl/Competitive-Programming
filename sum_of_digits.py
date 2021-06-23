"""
checking if a number has only 1 digit:
n = 15
inefficient way: len(str(n)) == 1
efficient way: n < 10
"""

n = int(input())

if len(str(n)) == 1:
    print(0)
else:
    count = 0
    while n >= 10:
        count += 1
        sum = 0
        for c in str(n):
            sum += int(c)
        n = sum
    print(count)
