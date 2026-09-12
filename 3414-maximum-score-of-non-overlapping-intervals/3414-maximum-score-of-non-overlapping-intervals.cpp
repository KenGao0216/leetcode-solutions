class Solution {
public:
    struct St{
        long long score =0;
        vector<int>ids;
    };
    St cmp(const St &a, const St &b){
        if(a.score != b.score) return (a.score > b.score ? a: b);
        return (a.ids < b.ids ? a : b);
    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>>a;
        for(int i = 0; i<n; ++i) a.push_back({intervals[i][0], intervals[i][1], intervals[i][2], i});
        sort(a.begin(), a.end());
        vector<int> starts(n);
        for(int i = 0; i<n; ++i) starts[i] = a[i][0];
        vector<int>nxt(n);
        for(int i = 0; i<n; ++i) nxt[i] = upper_bound(starts.begin(), starts.end(), a[i][1]) - starts.begin();
        
        vector<vector<St>>dp(n+1, vector<St>(5));
        for(int i = n-1; i>=0; --i){
            for(int k = 1; k<=4; ++k){
                St skip = dp[i+1][k];
                St take = dp[nxt[i]][k-1];
                take.score+=a[i][2];
                take.ids.push_back(a[i][3]);
                sort(take.ids.begin(), take.ids.end());
                dp[i][k] = cmp(skip, take);
            }
        }
        return dp[0][4].ids;

    }
};