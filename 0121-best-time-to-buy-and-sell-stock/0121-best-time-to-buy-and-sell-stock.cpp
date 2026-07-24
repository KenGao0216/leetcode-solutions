class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int mini = INT_MAX;
        for(int &p: prices){
            ans = max(ans, p-mini);
            mini = min(mini, p);
        }
        return ans;
    }
};