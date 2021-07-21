# problem link -> https://codingcompetitions.withgoogle.com/kickstart/round/00000000004361e3/000000000082b813

import sys
input = sys.stdin.readline

for i in range(1, int(input())+1):
    cell1, cell2, cell3 = map(int, input().split())
    cell4, cell6 = map(int, input().split())
    cell7, cell8, cell9 = map(int, input().split())
    count = 0
    if cell1-cell2 == cell2-cell3:
        count += 1
    if cell1-cell4 == cell4-cell7:
        count += 1
    if cell7-cell8 == cell8-cell9:
        count += 1
    if cell9-cell6 == cell6-cell3:
        count += 1

    d = {}
    if (cell1+cell9)%2 == 0:
        x = (cell1+cell9)//2
        if x in d:
            d[x] += 1
        else:
            d[x] = 1
    if (cell3+cell7)%2 == 0:
        x = (cell3+cell7)//2
        if x in d:
            d[x] += 1
        else:
            d[x] = 1
    if (cell4+cell6)%2 == 0:
        x = (cell4+cell6)//2
        if x in d:
            d[x] += 1
        else:
            d[x] = 1
    if (cell2+cell8)%2 == 0:
        x = (cell2+cell8)//2
        if x in d:
            d[x] += 1
        else:
            d[x] = 1

    if d:
        max_key = max(d, key=lambda x: d[x])
        count += d[max_key]
    print('Case #'+str(i)+': '+str(count))

