class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return an integer
    def solve(self, A, B):
        dp = [[0 for _ in range(B+1)] for _ in range(len(A)+1)]
    
        for i in range(len(dp)):
            dp[i][0] = 1
    
        for i in range(1, len(dp)):
            for j in range(len(dp[0])):
                if A[i-1] <= j:
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-A[i-1]])
                else:
                    dp[i][j] = dp[i-1][j]
    
        return dp[len(A)][B]
