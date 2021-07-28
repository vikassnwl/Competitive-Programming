# Solution 1
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n < 0:
            return False
        count = 0
        while n:
            count += 1
            n -= n&-n
        if count == 1:
            return True
        return False

# Solution 2
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if not n:
            return False
        return not n&n-1
