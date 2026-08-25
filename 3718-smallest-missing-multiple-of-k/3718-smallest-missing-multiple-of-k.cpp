class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(int i:nums)m[i]++;
        int i = k;
        while(m[i]) i+=k;
        return i;
    }
};