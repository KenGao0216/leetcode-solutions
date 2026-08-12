class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+5, 0);
        dp[0] = 0;
        for(int i = 1; i<=n; ++i){
            int maxi = arr[i-1];
            for(int len = 1; len<=min(i,k); ++len){
                maxi = max(maxi, arr[i-len]);
                dp[i] = max(dp[i], dp[i-len] + len*maxi);
                
            }
        }
        return dp[n];
    }
};

//1,15,7,9,2,5,10
//1 2  3 4 5 6 7

// i = 3
// len = 1 -> 7, dp[2]
// len = 2 -> 15, 7, dp[1]
// len = 3 -> 1,15,7, dp[0] = 0