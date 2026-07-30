class Solution {
public:
    int maximumProfit(vector<int>& present, vector<int>& future, int budget) {
        int n = present.size();
        
        vector<vector<int>>dp(n, vector<int>(budget+1, -1e6));
        dp[0][0] = 0;
        if(budget >=present[0] && future[0]-present[0] >0)dp[0][present[0]]=future[0]-present[0];
        for(int i = 1; i<n; ++i){
            dp[i] = dp[i-1];
            if(future[i]<=present[i]) continue;
            for(int j = budget; j>=present[i]; --j){
                if(dp[i-1][j-present[i]] != -1e6) dp[i][j] = max(dp[i-1][j], dp[i-1][j-present[i]]+future[i]-present[i]);
            }
        }
        return *max_element(dp[n-1].begin(), dp[n-1].end());
    }
};