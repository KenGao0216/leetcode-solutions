class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int i1 = -1, i2 = -1;
        int ans = INT_MAX;
        for(int i = 0; i<nums.size(); ++i){
            if(nums[i] == 1) i1 = i;
            else if(nums[i] == 2) i2 = i;
            if(i1!=-1 && i2!=-1) ans = min(ans, abs(i1-i2));
        }
        return ans == INT_MAX ? -1 : ans;
    }
};