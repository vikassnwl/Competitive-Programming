s = input()
def solve(l, r):
    if len(r) == 0:
        return
    x = l+' '+r
    #print(x)
    #print(*map(lambda z: chr(int(z)+96), x.split()))
    for z in x.split():
        if int(z) <= 26:
            pass
        else:
            break
    else:
        print(''.join(map(lambda z: chr(int(z)+96), x.split())))
    for i in range(len(r)):

        solve(l+' '+r[:i+1], r[i+1:])
if int(s) <= 26:
    print(chr(int(s)+96))
for i in range(len(s)):
    solve(s[:i+1], s[i+1:])
