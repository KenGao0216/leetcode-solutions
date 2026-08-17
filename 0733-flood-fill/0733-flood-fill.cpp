class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int org = image[sr][sc];
        vector<vector<bool>>vis(m, vector<bool>(n, false));
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        queue<pair<int,int>>q;
        q.push({sr,sc});
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            vis[cur.first][cur.second] = true;
            image[cur.first][cur.second] = color;
            for(int i = 0; i<4; ++i){
                int nx = cur.first+dx[i];
                int ny = cur.second+dy[i];
                if(nx>=0 && nx <m && ny>=0 && ny<n && !vis[nx][ny] && image[nx][ny] ==org)
                    q.push({nx, ny});
            }
        }
        return image;
    }
};