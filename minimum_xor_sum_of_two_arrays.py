class Solution:
    def minimumXORSum(self, nums1: List[int], nums2: List[int]) -> int:
        N = len(nums1)
        inf = 10**10

        @lru_cache(None)
        def go(index, mask):
            if index == N:
                return 0

            best = inf
            for x in range(N):
                if mask&(1<<x) == 0:
                    best = min(best, go(index+1, mask|(1<<x))+(nums2[x]^nums1[index]))
            return best
        return go(0, 0)
