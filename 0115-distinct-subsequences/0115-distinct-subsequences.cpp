class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<long>>dp(s.length()+1, vector<long>(t.length()+1, 0));
        for(int i = 0; i<=s.length(); ++i) dp[i][0] = 1;

        for(int i = 1; i<=s.length(); ++i){
            for(int j = 1; j<=min(i, (int)t.length()); ++j){
                dp[i][j] = dp[i-1][j];
                
                if(s[i-1] == t[j-1]) dp[i][j] = min((long)INT_MAX, dp[i][j] + dp[i-1][j-1]);
                
            }
        }
        return dp[s.length()][t.length()];
    }
};