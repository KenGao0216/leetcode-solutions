class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_o = INT_MAX;
        for(int i:nums1) if(i%2==1) min_o = min(min_o,i);
        for(int i:nums1) if(i%2==0) if (i<min_o && min_o!=INT_MAX) return false;
        return true;
    }
};