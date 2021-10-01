class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
	    int mod = 1e9+7;
        int dp[n+1][sum+1]{};
        dp[0][0] = 1;
        for(int i=1; i<=n; i++)
            for(int j=0; j<=sum; j++)
                if(j<arr[i-1]) dp[i][j] = dp[i-1][j];
                else dp[i][j] = (dp[i-1][j]+dp[i-1][j-arr[i-1]])%mod;
        return dp[n][sum];
	}
	  
};
