class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        int prev = lower-1;
        for(int i = 0; i<nums.size(); ++i){
            if(nums[i] < lower) continue;
            if(nums[i] > upper) break;
            if(nums[i] - prev > 1)  ans.push_back({prev+1, nums[i]-1});
            prev = nums[i];
        }
        if(prev < upper) ans.push_back({prev+1, upper});

        return ans;
    }
};

//1, 3, 7, 9, 12

//1, 1, 5, 7