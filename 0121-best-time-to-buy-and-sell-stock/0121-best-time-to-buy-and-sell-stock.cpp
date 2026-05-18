class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        int minp = INT_MAX;
        for(int &i:prices){
            minp = min(minp, i);
            ans = max(ans, i - minp);
        }
        return ans;
    }
};