class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int ans = 0;
        for(int i = 0; i<k; ++i) ans += nums[i];
        int cur = ans;
        for(int i = k; i<nums.size(); ++i){
            cur = cur - nums[i-k] + nums[i];
            ans = max(ans, cur);
        }
        return (double)((double)ans/(double)k);
    }
};