import sys
input = sys.stdin.readline
import re

for _ in range(int(input())):
    pattern = re.compile(r'</[a-z0-9]+>')
    mo = pattern.match(input())
    if mo:
        print('Success')
    else:
        print('Error')


https://www.codechef.com/LTIME97C/problems/HTMLTAGS
