class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());

        int ans = INT_MAX;
        while(l<=r){
            int m = (l+r)/2;
            if(f(m, nums) >=k) {
                ans = min(ans, m);
                r = m-1;
            }
            else l = m+1;
        }
        return ans;
    }

    int f(int m, vector<int>&nums){
        int cnt = 0;
        for(int i = 0; i<nums.size(); ++i){
            if(nums[i] <=m) {cnt++; i++;}
        }
        return cnt;
    }
};