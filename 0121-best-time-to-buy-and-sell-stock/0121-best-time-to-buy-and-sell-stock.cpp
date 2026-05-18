class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        vector<int>suf(n+1, 0);
        for(int i = n-1; i>=0; --i)
            suf[i] = max(suf[i+1], prices[i]);

        for(int i = 0; i<n; ++i){
            ans = max(ans, suf[i] - prices[i]);
        }
        return ans;
    }
};