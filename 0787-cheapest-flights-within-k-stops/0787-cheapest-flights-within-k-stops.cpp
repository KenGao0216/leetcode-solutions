class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>cost(n, INT_MAX);
        vector<vector<pair<int,int>>>g(n);
        for(auto &f:flights) g[f[0]].push_back({f[1], f[2]});
        int ans = INT_MAX;
        queue<pair<int,int>>q;
        q.push({src, 0});
        int stops = 0;
        while(!q.empty() && stops <=k){
            int sz = q.size();
            while(sz--){
                auto cur = q.front();
                q.pop();
                for(auto nxt: g[cur.first]){
                    if(cost[nxt.first]> cur.second + nxt.second){
                        cost[nxt.first] = cur.second + nxt.second;
                        q.push({nxt.first, cost[nxt.first]});
                    }
                }
            }
            stops++;
        }
        return cost[dst] == INT_MAX? -1 : cost[dst];
    }
};