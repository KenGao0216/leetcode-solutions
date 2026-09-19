class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        for(int i = 0; i<n; ++i){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int x = -nums[i];
            int l = i+1, r = n-1;
            while(l<r){
                if(nums[l]+nums[r] == x){
                    ans.push_back({nums[i], nums[l], nums[r]});
                    int lv = nums[l], rv = nums[r];
                    while(l< r && nums[r] == rv) r--;
                    while(l<r && nums[l] == lv) l++;
                }
                else if(nums[l] + nums[r] > x) --r;
                else ++l;
            }
        }
        return ans;
    }
};

//-4 -1 -1 0 1 2