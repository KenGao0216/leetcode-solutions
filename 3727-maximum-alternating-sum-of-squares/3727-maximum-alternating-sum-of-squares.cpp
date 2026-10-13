class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int &x:nums) x = abs(x);
        sort(nums.begin(), nums.end());
        //for(int i:nums) cout<<i<<" ";
        long long ans = 0;
        int n = nums.size();
        if(n%2 == 1) {
            ans+= 1LL* nums[n-1] * nums[n-1];
            for(int i = 0; i<n/2; ++i){
                ans+= 1LL* nums[n-i-2] * nums[n-i-2] - 1LL*nums[i] * nums[i];
            }
        }
        else{
            for(int i = 0; i<n/2; ++i){
            ans+= 1LL* nums[n-i-1] * nums[n-i-1] - 1LL*nums[i] * nums[i];
        }
        }
        return ans;
    }
};
// 5
// 0 1 2 3 4 5
