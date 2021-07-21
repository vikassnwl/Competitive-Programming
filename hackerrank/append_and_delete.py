# problem link -> https://www.hackerrank.com/challenges/append-and-delete/problem

import sys
input = sys.stdin.readline

s = input().rstrip()
t = input().rstrip()
k = int(input())

len_s = len(s)
len_t = len(t)

count = 0
for i in range(min(len_s, len_t)):
    if s[i] == t[i]:
        count += 1
    else:
        break

len_substr_s = len_s-count
len_substr_t = len_t-count

# if sum of length of s and t is equal to or less than k then we can convert s to t.
# We can remove all characters from s and append all character of t to make s equals to t.
# removing all elements from s will take n operations where n is the length of string s.
# then if we have the remaining operations greater than length of t, we need to apply 
# some x operations on empty strig to make it equal to length of t.
# appending all elements of t will take m operations where m is the length of string t
# that's why if k == n+m+x(k >= n+m) then output will be Yes.
if k >= len_s+len_t:
    print('Yes')
# if some beginnig characters are same in both of the strings then we will count
# them and subtract from the length of each string to find the length of unmatched trailing substrings.
# then if sum of length of both unmatched substrings are greater than k then you can't remove unmatched
# characters of s and append unmatched characters of t. Then answer will be No.
elif len_substr_s+len_substr_t > k:
    print('No')
# if sum of length of both unmatched substrings is less than or equal to k then you can remove unmatched
# characters of s and append unmatched characters of t and still can have 0 or more operations to perform.
# Now, you have to check if the remaining operations are even or odd. If remaining operations are even then
# you can keep removing and appendig last character of s and will get the same string at the end and will print Yes.
# If remaining operations are odd then you can keep removing and appendig last character of s and will 
# get the string without last character and you will print No.
elif (k-len_substr_s-len_substr_t)%2 == 0:
    print('Yes')
else:
    print('No')
