class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(), nums.end());
        unordered_map<int,int>m;
        for(int i:s) m[i]++;
        int ans = 0;
        for(int i:s){
            if(m.count(i-1) == 0) {
                int cur =i;
                while(m.count(cur)) ++cur;
                ans = max(ans, cur-i);
            }
        }
        return ans;
    }
};