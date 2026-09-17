class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int>dp(n+1, 2e5);
        int l = 0, r = 0;
        int sum = 0;
        int ans = INT_MAX;
        while(r<n && l<=r){
            sum+=arr[r];
            while(sum > target){
                sum-=arr[l];
                ++l;
            }
            dp[r+1] = dp[r];
            if(sum==target){
                dp[r+1] = min(dp[r], r-l+1);
                if(dp[l]!=2e5){
                    ans = min(ans, dp[l]+r-l+1);
                }
            }
            ++r;
        }
        return ans == INT_MAX? -1 : ans;
    }
};