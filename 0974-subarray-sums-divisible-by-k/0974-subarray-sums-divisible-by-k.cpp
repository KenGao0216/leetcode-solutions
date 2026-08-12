class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>m(k+1,0);
        m[0] = 1;
        int sum=0, ans = 0;
        for(int i = 0; i<n; ++i){
            sum= ((sum + nums[i] % k)+k) % k;
            ans+=m[sum];
            m[sum]++;
        }
        return ans;
    }
};
