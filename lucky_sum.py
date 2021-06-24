#creating lucky vector
lucky_arr = [4, 7]

i = 0
for _ in range(8):
    len_arr = len(lucky_arr)
    while i < len_arr:
        lucky_arr += [lucky_arr[i]*10+4, lucky_arr[i]*10+7]
        i += 1

lucky_arr += [4444444444]

#taking input
l, r = map(int, input().split())

#finding the index of the lucky number which is equal to l or comes just after l
for i in range(len(lucky_arr)):
    if lucky_arr[i] >= l:
        break

#here comes the calculation
sum = 0
while lucky_arr[i] < r:
    sum += (lucky_arr[i]-l+1)*lucky_arr[i]
    l = lucky_arr[i]+1
    i += 1

sum += (r-l+1)*lucky_arr[i]

print(sum)

