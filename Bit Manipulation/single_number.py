# Solution 1
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ans = 0
        for i in range(32):
            set_bits_count = 0
            for num in nums:
                set_bits_count += num>>i&1
            if set_bits_count&1:
                ans += 1<<i
        if ans >= 1<<31:
            ans -= 1<<32
        return ans

# Solution 2
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ans = 0
        for num in nums:
            ans ^= num
        return ans
