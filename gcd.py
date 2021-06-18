# A recursive function to calculate gcd of two numbers
def gcd(x, y):
  if y == 0:
    return x
  return gcd(y, x%y)
