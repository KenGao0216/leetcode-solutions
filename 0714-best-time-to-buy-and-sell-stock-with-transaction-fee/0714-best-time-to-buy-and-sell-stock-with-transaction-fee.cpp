class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if(n==1) return 0;
        //vector<vector<int>>dp(n, vector<int>(2, -1e6));
        int b = -prices[0];
        int s = 0;
        int ans = 0;
        for(int i = 1; i<n; ++i){
            s = max(s, b+prices[i]-fee);
            b = max(b, s-prices[i]);
            ans = max(ans, s);
            //dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i] - fee);
            //dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);
        }
        return ans;
    }
};