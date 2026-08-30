class Solution {
public:
    int numberOfPatterns(int m, int n) {
        int skip[10][10];
        skip[1][3] = 2, skip[3][1] = 2,
        skip[1][7] = 4, skip[7][1] = 4,
        skip[1][9] = 5, skip[9][1] = 5,
        skip[2][8] = 5, skip[8][2] = 5,
        skip[3][7] = 5, skip[7][3] = 5,
        skip[3][9] = 6, skip[9][3] = 6,
        skip[4][6] = 5, skip[6][4] = 5,
        skip[7][9] = 8, skip[9][7] = 8;
        vector<bool>vis(10, false);
        int ans=0;
        ans+=4*dfs(1,1, m, n, vis, skip);
        ans+=4*dfs(2,1, m, n, vis, skip);
        ans+=dfs(5,1, m, n, vis, skip);
        return ans;
    }

    int dfs(int cur, int len, int m, int n, vector<bool>&vis, int skip[10][10]){
        if(len>n) return 0;
        int cnt = len >= m ? 1 : 0;
        vis[cur] = true;
        for(int nxt = 1; nxt<=9; ++nxt){
            if(!vis[nxt]){
                int bridge = skip[cur][nxt];
                if(bridge == 0 || vis[bridge]) cnt +=dfs(nxt, len+1, m, n, vis, skip);
            }
        }
        vis[cur] = false;
        return cnt;
    }
    
};