class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int ans = -1e5;
        int sum = 0;
        int n = nums.size();
        int sum1 = 0, tot=0;
        for(int i = 0; i<n; ++i){
            sum+=nums[i];
            tot+=nums[i];
            ans = max(ans, sum);
            if(sum<0) sum = 0;
        }
        for(int i = 0; i<n; ++i){
            sum1+=nums[i];
            ans = max(ans, tot-sum1);
            if(sum1>0) sum1 = 0;
        }
        return *max_element(nums.begin(), nums.end()) < 0? *max_element(nums.begin(), nums.end()): ans;
    }
};