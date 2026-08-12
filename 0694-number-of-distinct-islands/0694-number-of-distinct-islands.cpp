class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int id = 0;
        vector<vector<bool>>vis(m, vector<bool>(n,false));
        vector<set<pair<int,int>>>islands(m*n);
        for(int i = 0; i<m; ++i){
            for(int j = 0; j<n; ++j){
                if(grid[i][j] == 1 && !vis[i][j]){
                    dfs(i, j, grid, vis, m, n, id, islands);
                    id++;
                }
            }
        }
        vector<bool>flag(id, false);
        int flags = 0;
        for(int i = 0; i<id; ++i){
            if(flag[i]) continue;
            for(int k =0; k<id; ++k){
                if(islands[i].size() == islands[k].size() && i!=k){
                    bool isSame = true;
                    int diffx = islands[i].begin()->first - islands[k].begin()->first;
                    int diffy = islands[i].begin()->second - islands[k].begin()->second;
                    for(int j = 0; j<islands[i].size(); ++j){
                        auto it1 = next(islands[i].begin(), j);
                        auto it2 = next(islands[k].begin(), j);

                        if (!(it1->first - diffx == it2->first &&
                            it1->second - diffy == it2->second)) {
                            isSame = false;
                            break;
                        }
                    }
                    if(isSame) {flag[k]= true; flags++;}
                }
            }
        }
        return id-flags;
    }

    void dfs(int x, int y, vector<vector<int>>&grid, vector<vector<bool>>&vis, int m, int n, int id, vector<set<pair<int,int>>>&islands){
            vis[x][y] = true;
            islands[id].insert({x,y});
            for(int i = 0; i<4; ++i){
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny] && grid[nx][ny] == 1){
                    dfs(nx, ny, grid, vis, m, n, id, islands);
                }
            }
    }
};