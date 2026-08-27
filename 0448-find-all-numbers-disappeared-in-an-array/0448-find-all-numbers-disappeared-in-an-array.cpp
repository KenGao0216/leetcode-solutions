class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            vector<int>ans;
            for(int i = 1; i<=nums.size(); ++i){
                auto it = lower_bound(nums.begin(), nums.end(), i);
                if(it==nums.end() || *it != i) ans.push_back(i);
            }
            return ans;
    }
};