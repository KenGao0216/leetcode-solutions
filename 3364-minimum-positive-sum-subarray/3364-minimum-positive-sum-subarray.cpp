class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;
        for(int i = 0; i<nums.size()-l+1; ++i){
            int sum = 0;
            for(int j = 0; j<min(r, (int)nums.size()-i); ++j){
                sum+=nums[i+j];
                if(j+1>=l && j+1 <=r && sum > 0) ans = min(ans, sum);
            }
        }
        return ans==INT_MAX? -1: ans;
    }
};