class Solution {
public:
    int longestValidParentheses(string s) {
            int n  =s.length();
            vector<int>dp(n+1, 0);
            for(int i = 0; i<n; ++i){
                if(s[i] == ')'){
                    if(i>0 && s[i-1] == '(') dp[i] = i>=2? dp[i-2]+2 : 2;
                    else if(i>0 && s[i-1] == ')'){
                        int j = i - dp[i-1] - 1;
                        if(j>=0 && s[j] == '(') dp[i] = dp[i-1] + (j==0 ? 0 :dp[j-1]) + 2;
                    }
                }
            }
            return *max_element(dp.begin(), dp.end());


    }
};