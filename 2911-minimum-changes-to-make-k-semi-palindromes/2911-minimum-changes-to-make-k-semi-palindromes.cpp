class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        // proper divisors of each length
        vector<vector<int>> divs(n + 1);
        for (int d = 1; d <= n; d++)
            for (int len = 2 * d; len <= n; len += d)
                divs[len].push_back(d);

        // cost[i][j] = min changes to make s[i..j] a semi-palindrome
        vector<vector<int>> cost(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int len = j - i + 1;
                for (int d : divs[len]) {
                    int cnt = len / d, changes = 0;
                    for (int r = 0; r < d; r++) {
                        for (int a = 0, b = cnt - 1; a < b; a++, b--) {
                            if (s[i + r + a * d] != s[i + r + b * d]) changes++;
                        }
                    }
                    cost[i][j] = min(cost[i][j], changes);
                }
            }
        }

        // dp[i][j] = min cost to split first i chars into j parts
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(i, k); j++) {
                for (int m = j - 1; m < i; m++) {
                    if (dp[m][j - 1] == INF || cost[m][i - 1] == INF) continue;
                    dp[i][j] = min(dp[i][j], dp[m][j - 1] + cost[m][i - 1]);
                }
            }
        }
        return dp[n][k];
    }
};