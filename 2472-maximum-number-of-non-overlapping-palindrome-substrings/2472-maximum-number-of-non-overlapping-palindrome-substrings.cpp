class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        vector<int>dp(n+1);
        for(int i = k; i<=n; ++i){
            dp[i] = dp[i-1];
            string s1 = s.substr(i-k, k);
            if(isP(s1)) dp[i] = max(dp[i], dp[i-k] + 1);
            if(i > k){
                string s1 = s.substr(i-k-1, k+1);
                if(isP(s1)) dp[i] = max(dp[i], dp[i-k-1]+1);
            }
        }
        return dp[n];
    }
    bool isP(string s){
        for(int i = 0; i<s.length()/2; ++i){
            if(s[i] != s[s.length()-i-1]) return false;
        }
        return true;
    }
};