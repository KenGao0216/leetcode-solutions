class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int>m(n+1,0);
        vector<int>ans;
        for(int &i:nums) m[i]++;
        for(int i = 1; i<=n; ++i) if(m[i] == 0 || m[i]==2) ans.push_back(i);
        if(m[ans[0]] < m[ans[1]]) swap(ans[0], ans[1]);
        return ans;
    }
};