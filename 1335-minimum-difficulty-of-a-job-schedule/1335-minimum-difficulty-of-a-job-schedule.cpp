class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n<d) return -1;
        vector<vector<int>>dp(d+1, vector<int>(n+1,1e6));
        dp[0][0] = 0;
        for(int day =1; day<=d; ++day){
            for(int i = day; i<=n; ++i){
                int maxi = 0;
                for(int j = i-1; j>=day-1; --j){
                    maxi = max(maxi, jobDifficulty[j]);
                    dp[day][i] = min(dp[day][i], dp[day-1][j] + maxi);
                }
            }
        }
        
        return dp[d][n];
    }
};