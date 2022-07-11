s = "abc"
n = len(s)
substrs = []
for i in range(2**n):
    substr = ""
    for j in range(n):
        if i&(1<<j):
            substr += s[j]
    substrs.append(substr)

print(substrs)
print(len(substrs))
