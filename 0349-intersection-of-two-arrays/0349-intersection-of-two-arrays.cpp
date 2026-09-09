class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>s; unordered_set<int>ans;
        for(int i:nums1) s.insert(i);
        for(int i:nums2) {
            if(s.find(i)!= s.end() && ans.find(i) == s.end()) ans.insert(i);
        }
        return vector<int>(ans.begin(), ans.end());
    }
};