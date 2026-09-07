class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>>dp(n, vector<int>(n, 0));
        string ans = s.substr(0, 1);
        int mx = 1;
        for(int i = 0; i<n; ++i) {
            dp[i][i] = 1;
            if(i < n-1 && s[i] == s[i+1]) {
                dp[i][i+1] =1;
                mx = 2;
                ans = s.substr(i, 2);
            }
        }
        
        for(int len = 3; len<=n; ++len){
            for(int i = 0; i<=n-len; ++i){
                int j = i+len-1;
                if(s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = 1;
                    if(len > mx){
                        mx = len;
                        ans = s.substr(i, len);
                    }
                }
            }
        }
        return ans;
        
        

    }
};