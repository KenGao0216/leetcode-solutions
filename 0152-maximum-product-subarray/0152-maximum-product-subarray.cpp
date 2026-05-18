class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int pre = 1;
        int suf =1;

        for(size_t i = 0; i<n; ++i){
            if(pre == 0) pre = 1;
            if(suf == 0) suf = 1;
            pre*=nums[i];
            suf*=nums[n-i-1];
            ans = max({ans, pre, suf});
        }
        return ans;
    }
};