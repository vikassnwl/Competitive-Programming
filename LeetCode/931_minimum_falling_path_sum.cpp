class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        int dp[n+1][m+2];
        for(int i=0; i<m+2; i++) dp[n][i] = 0;
        for(int i=0; i<n; i++) dp[i][0] = INT_MAX;
        for(int i=0; i<n; i++) dp[i][m+1] = INT_MAX;
	
        for(int i=n-1; i>=0; i--){
            for(int j=1; j<m+1; j++){
                dp[i][j] = arr[i][j-1]+min(dp[i+1][j], min(dp[i+1][j+1], dp[i+1][j-1]));
            }
        }
        int ans = INT_MAX;
        for(int j=1; j<m+1; j++)
            ans = min(ans, dp[0][j]);
        return ans;
    }
};
