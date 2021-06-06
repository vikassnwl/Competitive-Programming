# Solution 1
import math

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        sum = 0; best = -math.inf
        for i in range(len(nums)):
            sum = max(nums[i], sum+nums[i])
            best = max(best, sum)
        
        return best
      
      
# Solution 2
class Solution:
    def maxSubArray(self, nums):
        for i in range(1, len(nums)):
            nums[i] = max(nums[i], nums[i]+nums[i-1])
        return max(nums)
