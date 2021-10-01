class Solution {
public:
    int minPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        int dp[n+1][m+1];
        for(int i=0; i<m+1; i++) dp[n][i] = INT_MAX;
        for(int i=0; i<n+1; i++) dp[i][m] = INT_MAX;
        dp[n][m-1] = dp[n-1][m] = 0;
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                dp[i][j] = arr[i][j]+min(dp[i][j+1], dp[i+1][j]);
            }
        }
        return dp[0][0];
    }
};
