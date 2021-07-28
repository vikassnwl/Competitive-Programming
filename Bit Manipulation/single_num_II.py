class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ans = 0
        for i in range(32):
            set_bits_count = 0
            for num in nums:
                if num&1<<i:
                    set_bits_count += 1
            ans += set_bits_count%3*2**i
        if ans >= 2**31:
            ans -= 2**32
        return ans
