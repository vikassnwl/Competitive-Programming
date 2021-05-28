numberOfRows, numberOfGroups = map(int, input().split())
oneSeat = 0
twoSeats = numberOfRows * 2
fourSeats = numberOfRows

liSoldiers = list(map(int, input().split()))
liLeft = [0, 0, 0]

blnOk = True

liSoldiers.sort()
liSoldiers.reverse()

for i in range(len(liSoldiers)):
    while liSoldiers[i]>=3 and blnOk:
        if fourSeats>0:
            liSoldiers[i] -= 4
            fourSeats -= 1
        elif twoSeats > 0:
            liSoldiers[i] -= 2
            twoSeats -= 1
        else:
            blnOk = false;

    if blnOk and liSoldiers[i] > 0:
        liLeft[liSoldiers[i]] += 1

while liLeft[2]>0 and blnOk:
    if twoSeats>0:
        twoSeats -= 1
    elif fourSeats>0:
        fourSeats -= 1
        oneSeat += 1
    else:
        liLeft[1] += 2
    liLeft[2] -= 1

if liLeft[1] > (oneSeat + twoSeats + fourSeats * 2):
    blnOk = False

print('YES' if blnOk else 'NO')
