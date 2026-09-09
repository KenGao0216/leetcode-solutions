class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
         unordered_map<int,vector<int>>m;
         for(int i =0; i<nums.size(); ++i){
            int x = nums[i];
            if(!m[x].empty() && abs(i-m[x].back()) <=k) return true;
            m[x].push_back(i);
         }
         
         return false;
    }
};