class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n==1) return 0;
        vector<int>buy(k+1, -1e6);
        vector<int>sell(k+1, -1e6);
        buy[0] = -prices[0];
        sell[0] = 0;
        for(int i = 1; i<n; ++i){
            for(int j = 1; j<=k; ++j){
                    buy[j] =  max(buy[j], sell[j]-prices[i]);
                    sell[j] = max(sell[j], buy[j-1]+prices[i]);
            }
            buy[0] = max(buy[0], -prices[i]);
        }
        return *max_element(sell.begin(), sell.end());
    }
};