class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>maxi(n+1, 0);
        vector<int>mini(n+1, INT_MAX);
        for(int i = 1; i<=n; ++i){
            maxi[i] = max(maxi[i-1], nums[i-1]);
        }
        for(int i = n-1; i>=0; --i){
            mini[i] = min(mini[i+1], nums[i]);
        }
        for(int i = 0; i<n; ++i){
            if(maxi[i+1] - mini[i] <=k) return i;
        }
        return -1;
    }
};