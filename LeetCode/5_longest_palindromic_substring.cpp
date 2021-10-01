class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int dp[n+1][n+1];
        for(int i=0; i<=n; i++) dp[0][i] = dp[1][i] = 1;
        int resL=1, resE=1;
        for(int i=2; i<=n; i++){
            for(int j=i; j<=n; j++){
                if(s[j-1]==s[j-i] and dp[i-2][j-1]==1)
                    dp[i][j] = 1, resL=i, resE=j;
                else dp[i][j] = 0;
            }
        }
        return s.substr(resE-resL, resL);
    }
};
