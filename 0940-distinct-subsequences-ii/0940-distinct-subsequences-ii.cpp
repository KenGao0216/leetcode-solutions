class Solution {
public:
    int distinctSubseqII(string s) {
        const int mod = 1e9+7;
        int n = s.length();
        vector<int>last(26, -1);
        vector<long long>dp(n+1,0);
        dp[0] = 1;
        for(int i = 1; i<=n; ++i){
            dp[i] = (dp[i-1]*2)%mod;
            int c = s[i-1] - 'a';
            if(last[c] != -1) dp[i]= (dp[i] - dp[last[c]-1] + mod)%mod;
            last[c] = i;
        }
        return (dp[n]-1 + mod) % mod;
    }
};

 
