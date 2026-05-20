class Solution {
public:
    vector<int> maxUpgrades(vector<int>& count, vector<int>& upgrade, vector<int>& sell, vector<int>& money) {
        int n = (int)count.size();
        vector<int>res;
        for(int i = 0; i<n; ++i){
            int lo = 0, hi = count[i];
            int mid = (lo+hi)/2;
            int ans = 0;
            while(lo<=hi){
                if(1LL*upgrade[i] * mid <= 1LL*(count[i]-mid)*sell[i] + (1LL*money[i])) {
                    ans = max(ans, mid);
                    lo = mid+1;
                }
                else hi = mid-1;
                mid = (lo+hi)/2;
            }
            res.push_back(ans);
        }
        return res;
    }
};