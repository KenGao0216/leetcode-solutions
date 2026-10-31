class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();

        // dp[x][y][d]: ways to enter (x,y) with last move d (0 = right, 1 = down)
        vector<vector<array<long long,2>>> dp(m, vector<array<long long,2>>(n, {0,0}));
        vector<vector<array<bool,2>>> seen(m, vector<array<bool,2>>(n, {false,false}));

        queue<tuple<int,int,int>> q;
        dp[0][0][0] = 1; 
        seen[0][0][0] = true;
        q.push({0, 0, 0});

        while (!q.empty()) {
            auto [x, y, d] = q.front();
            q.pop();
            long long cur = dp[x][y][d];

            bool canRight, canDown;
            if (grid[x][y] == 0) {
                canRight = canDown = true;   // empty: free choice
            } else {
                canRight = (d == 1);         // entered going down -> reflect right
                canDown  = (d == 0);         // entered going right -> reflect down
            }

            // move right
            if (canRight && y + 1 < n) {
                dp[x][y+1][0] = (dp[x][y+1][0] + cur) % MOD;
                if (!seen[x][y+1][0]) {
                    seen[x][y+1][0] = true;
                    q.push({x, y+1, 0});
                }
            }
            // move down
            if (canDown && x + 1 < m) {
                dp[x+1][y][1] = (dp[x+1][y][1] + cur) % MOD;
                if (!seen[x+1][y][1]) {
                    seen[x+1][y][1] = true;
                    q.push({x+1, y, 1});
                }
            }
        }
        return (dp[m-1][n-1][0] + dp[m-1][n-1][1]) % MOD;
    }
};