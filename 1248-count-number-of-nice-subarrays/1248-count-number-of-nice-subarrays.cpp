class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>oid;
        oid.push_back(-1);
        for(int i = 0; i<nums.size(); ++i) if(nums[i]%2==1) oid.push_back(i);
        oid.push_back(n);
        if(oid.size()-2 < k) return 0;
        int ans = 0;
        for(int i = 1; i<oid.size()-k; ++i){
            int x = oid[i] - oid[i-1];
            int y = oid[i+k] - oid[i+k-1];
            ans+= x*y;
        }
        //-1 0 1 3 4 5
        return ans;

    }
};
