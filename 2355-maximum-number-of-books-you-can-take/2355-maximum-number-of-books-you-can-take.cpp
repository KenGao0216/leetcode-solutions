class Solution {
public:
    long long maximumBooks(vector<int>& books) {
        int n = books.size();
        long long ans = 0;
        stack<pair<int,long long>>s;
        for(int i = 0; i<n; ++i){
            long long cur;
            while(!s.empty() && books[s.top().first] >= books[i] - (i-s.top().first)) s.pop();
            if(s.empty()) {
                long long len = min(i+1, books[i]);
                cur = 1LL*books[i] * len - (len * (len-1))/2;
            }
            else {
                int j = s.top().first;
                long long len = i-j;
                cur = s.top().second + 1LL*books[i] * len - (len * (len-1))/2;
            }
            ans = max(ans, cur);
            s.push({i, cur});
        }
        return ans;
    }
};