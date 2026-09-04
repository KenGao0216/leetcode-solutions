class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>g(n);
        
        for(auto e:edges){
            g[e[0]].push_back({e[1], 0});
            g[e[1]].push_back({e[0], 1});
        }
        vector<int>ans(n);
        dfs1(ans, 0, -1, g);
        dfs2(ans, 0, -1, g);
        return ans;


    }   
    void dfs1(vector<int>&ans, int cur, int par, vector<vector<pair<int,int>>>&g){
        for(auto nxt:g[cur]){
            if(nxt.first == par) continue;
            ans[0]+=nxt.second;
            dfs1(ans, nxt.first, cur, g);
        }
    }
    void dfs2(vector<int>&ans, int cur, int par, vector<vector<pair<int,int>>>&g){
        for(auto nxt:g[cur]){
            if(nxt.first == par) continue;
            ans[nxt.first] = nxt.second == 0 ? ans[cur] +1 : ans[cur]-1;
            dfs2(ans, nxt.first, cur, g);
        }
    }
};