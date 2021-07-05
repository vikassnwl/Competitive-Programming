# A recursive function to calculate gcd of two numbers
def gcd(x, y):
  if y == 0:
    return x
  return gcd(y, x%y)


# Python implementation to find GCD of a list of numbers
def gcd(a, b):
    while b > 0:
        a, b = b, a % b
    return a

a = [4, 10, 16, 14]

result = a[0]
for i in a[1:]:
    result = gcd(result, i)

print(result)
