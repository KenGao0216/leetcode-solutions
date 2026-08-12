class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>vis(m, vector<bool>(n,false));
        set<vector<pair<int,int>>>ans;
        for(int i = 0; i<m; ++i){
            for(int j = 0; j<n; ++j){
                if(grid[i][j] == 1 && !vis[i][j]){
                    vector<pair<int,int>>shape;
                    dfs(i, j, i, j, grid, vis, m, n, shape);
                    ans.insert(shape);
                }
            }
        }
        return ans.size();
    }

    void dfs(int x, int y, int sx, int sy,vector<vector<int>>&grid, vector<vector<bool>>&vis, int m, int n, vector<pair<int,int>>&shape){
            vis[x][y] = true;
            shape.push_back({x-sx,y-sy});
            for(int i = 0; i<4; ++i){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny] && grid[nx][ny] == 1){
                    dfs(nx, ny, sx, sy, grid, vis, m, n, shape);
                }
            }
    }
};