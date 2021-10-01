class Solution
{
    public:
    int dp[1000][1000];
    int ks(int W, int wt[], int val[], int n){
        if(n==0||W==0) return 0;
        if(dp[n-1][W-1]==-1){
            int exc = ks(W, wt, val, n-1);
            if(wt[n-1]<=W) dp[n-1][W-1] = max(val[n-1]+ks(W-wt[n-1], wt, val, n-1), exc);
            else dp[n-1][W-1] = exc;
        }
        return dp[n-1][W-1];
    }
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        memset(dp, -1, sizeof dp);
        return ks(W, wt, val, n);
    }
};
