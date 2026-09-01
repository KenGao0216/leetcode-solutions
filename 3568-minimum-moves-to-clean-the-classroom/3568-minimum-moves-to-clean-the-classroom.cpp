class Solution {
public:
    struct State{int x,y,energy, mask;};

    int dirx[4] = {1, -1, 0, 0};
    int diry[4] = {0,0,1,-1};
    int minMoves(vector<string>& classroom, int energy) {
        int m =classroom.size();
        int n = classroom[0].length();
        vector<vector<int>>litters(m, vector<int>(n,-1));
        int nl = 0, sX, sY;
        for(int i = 0; i<m; ++i){
            string s = classroom[i];
            for(int j = 0; j<s.length(); ++j){
                if(s[j] == 'L') {litters[i][j] = nl; nl++;}
                if(s[j] == 'S'){sX = i; sY = j;}
            }
        }
        vector<vector<vector<vector<bool>>>> vis(m, vector<vector<vector<bool>>>(n, vector<vector<bool>>(energy+1, vector<bool>(1<<nl, false))));

        queue<State>q;
        q.push({sX, sY, energy, 0});
        vis[sX][sY][energy][0] = true;
        int moves = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i<sz; ++i){
                auto cur = q.front();
                q.pop();
                if(cur.mask == (1<<nl)-1) return moves;
                if(cur.energy == 0) continue;
                for(int j = 0; j<4; ++j){
                    int nx = cur.x + dirx[j];
                    int ny = cur.y + diry[j];
                    if(nx>=0 && nx < m && ny>=0 && ny < n && classroom[nx][ny] != 'X'){
                        int nE = (classroom[nx][ny] == 'R') ? energy : cur.energy-1;
                        int nMask = cur.mask;
                        if(litters[nx][ny]!=-1) nMask = nMask | (1 << litters[nx][ny]);
                        if(!vis[nx][ny][nE][nMask]){
                            vis[nx][ny][nE][nMask] = true;
                            q.push({nx, ny, nE, nMask});
                        }
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};