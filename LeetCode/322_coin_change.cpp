class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        dp[0] = 0;
        for(int i=1; i<=amount; i++){
            int ans = INT_MAX;
            for(int coin: coins){
                if(coin<=i) ans = min(ans, dp[i-coin]);
            }
            dp[i] = ans!=INT_MAX?ans+1:ans;
        }
        return dp[amount]!=INT_MAX?dp[amount]:-1;
    }
};
