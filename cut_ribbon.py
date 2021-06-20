"""
The problem is to maximize x+y+z subject to ax+by+cz=n. Constraints are low, so simply iterate over two variables (say x and y) and find the third variable (if any) from the second equation. Find the maximum over all feasible solutions.

Other approaches: Use dynamic programming with each state being the remainder of ribbon. Select the next piece to be a, b or c.
"""
n, a, b, c = map(int, input().split())

import math
max_pieces = -math.inf

for x in range(4001):
    for y in range(4001):
        zc = n-(x*a+y*b)
        if zc < 0:
            break
        if zc%c == 0:
            max_pieces = max(max_pieces, x+y+zc//c)

print(max_pieces)
