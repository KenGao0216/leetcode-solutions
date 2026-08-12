class Solution {
public:
    vector<int>p;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i<m*n; ++i) p.push_back(i);
        vector<vector<bool>>vis(m, vector<bool>(n,false));
        for(int i = 0; i<m; ++i){
            for(int j = 0; j<n; ++j){
                if(grid[i][j] == '1' && !vis[i][j]) dfs(i,j, vis, grid, i*n+j, m, n);
            }
        }
        unordered_set<int>s;
        for(int i = 0; i<m; ++i){
            for(int j = 0; j<n; ++j){
                if(grid[i][j] == '1') s.insert(find(i*n+j));
            }
        }
        return s.size();
    }

    int find(int a){
        if(p[a]==a) return a;
        return p[a] = find(p[a]);
    }
    void uni(int a, int b){
        int pa = find(a);
        int pb = find(b);
        p[pb] = pa;
        return;
    }

    void dfs(int x, int y, vector<vector<bool>>&vis, vector<vector<char>>&grid, int par, int m, int n){
        vis[x][y] = true;
        for(int i = 0; i<4; ++i){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && nx < m && ny>=0 && ny<n && !vis[nx][ny] && grid[nx][ny] == '1'){
                uni(par, nx*n+ny);
                dfs(nx, ny, vis, grid, par, m, n);
            }
        }
    }

};