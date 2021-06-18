#domino
"""
condition 1:
    if sum of upper half is even and sum of lower half is even then we don't need to perform any action. That's why result is 0.

condition 2:
    if sum of upper half is odd and sum of lower half is odd and there is atleast one different parity means we can rotate one domino with different parity to make both upper half and lower half sums even. So the result will be 1.
    If there is no different parity while the sum of both upper half and lower half is odd, then the result will be -1.

condition 3:
    If some of upper half and lower half are different i.e one is even and other is odd or one is odd and other is even, then we cannot make both of them even because if we try to rotate dominos with different parity it will make even sum to odd and odd sum to even and we will come up with the initial situation and if we rotate the domino with the same parity then there will be no difference in situation.
"""

n = int(input())
matrix = []
for _ in range(n):
    matrix.append(list(map(int, input().split())))

uh_sum = 0
lh_sum = 0
diff_parity = False
for i, j in matrix:
    if (i+j)%2 == 1:
        diff_parity = True
    uh_sum += i
    lh_sum += j

if uh_sum%2 == 0 and lh_sum%2 == 0:
    print(0)
elif uh_sum%2 == 1 and lh_sum%2 == 1 and diff_parity:
    print(1)
else:
    print(-1)
