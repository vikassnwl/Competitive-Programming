#solution 1 using recursion O(2^n)
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        def solve(arr, n, i, subarr, result):
            if i == n:
                result.append(subarr)
                return
            solve(arr, n, i+1, subarr+[arr[i]], result)
            solve(arr, n, i+1, subarr, result)
        
        result = []
        solve(nums, len(nums), 0, [], result)
        return result
      
      
#solution 2 using bitmask O(Nx2^N)
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        output = []
        for mask in range(1<<len(nums)):
            result = []
            for i in range(len(nums)):
                if mask&(1<<i):
                    result.append(nums[i])
            output.append(result)
            
        return output
