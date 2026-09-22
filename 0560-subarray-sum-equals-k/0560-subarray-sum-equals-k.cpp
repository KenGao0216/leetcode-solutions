class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int ans = 0;
        m[0] = 1;
        int pre = 0;
        for(int i = 0; i<nums.size(); ++i){
            pre+=nums[i];
            if(m.count(pre-k) != 0) ans+=m[pre-k];
            m[pre]++;
        }
        return ans;
    }
};

// 1 1
// 3 1
// 6