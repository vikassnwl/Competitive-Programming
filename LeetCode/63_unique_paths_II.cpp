class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        long long dp[m][n];
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                dp[i][j] = obstacleGrid[i][j]^1;
        
        for(int i=n-2; i>=0; i--)
            if(dp[m-1][i+1]==0)
                dp[m-1][i] = 0;
        
        for(int i=m-2; i>=0; i--)
            if(dp[i+1][n-1]==0)
                dp[i][n-1] = 0;

        for(int i=m-2; i>=0; i--)
            for(int j=n-2; j>=0; j--)
                if(dp[i][j]!=0)
                    dp[i][j] = dp[i+1][j]+dp[i][j+1];
        
        return dp[0][0];
    }
};
