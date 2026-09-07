class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9+7;
        int n = s.length();
        vector<long long>dp(n+1,0);
        dp[0] = 1;
        vector<int>last(26, 0);
        for(int i = 1; i<=n; ++i){
            int c = s[i-1] - 'a';
            dp[i] = dp[i-1]*2;
            if(last[c] != 0){
                dp[i] = (dp[i] - dp[last[c] - 1] + MOD) % MOD;
            }
            last[c] = i;
        }
        
        return (dp[n]-1 + MOD) % MOD;
    }
};