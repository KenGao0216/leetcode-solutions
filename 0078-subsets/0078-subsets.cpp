class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>path;
        f(0, path, nums);
        return ans;
    }

    void f(int start, vector<int>& path, vector<int>nums){
            ans.push_back(path);
            if(path.size() == nums.size()) return;
            for(int i = start; i<nums.size(); ++i){
                path.push_back(nums[i]);
                f(i+1, path, nums);
                path.pop_back();
            }
    }
};