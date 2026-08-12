class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>m;
        m[0] = 1;
        int sum=0, ans = 0;
        for(int i = 0; i<n; ++i){
            sum= (sum + nums[i]+k) % k;
            ans+=m[sum];
            m[sum]++;
        }
        return ans;
    }
};
