class Solution {
public:
    long long maximumBooks(vector<int>& books) {
        int n = books.size();
        if(n==1) return books[0];
        vector<long long>dp(n, 0);
        dp[0] = books[0];
        stack<int>s;
        s.push(0);
        for(int i = 1; i<n; ++i){
            while(!s.empty() && books[s.top()] >= books[i] - (i-s.top())) s.pop();
            if(s.empty()) {
                long long len = min(i+1, books[i]);
                dp[i] = 1LL*books[i] * len - (len * (len-1))/2;
            }
            else {
                int j = s.top();
                long long len = i-j;
                dp[i] = dp[j] + 1LL*books[i] * len - (len * (len-1))/2;
            }
            s.push(i);
        }
        return *max_element(dp.begin(), dp.end());
    }
};