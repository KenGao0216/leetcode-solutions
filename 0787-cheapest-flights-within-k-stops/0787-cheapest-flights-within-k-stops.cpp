class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>>cost(n, vector<int>(k+2,INT_MAX));
        vector<vector<pair<int,int>>>g(n);
        for(auto &f:flights) g[f[0]].push_back({f[1], f[2]});
        int ans = INT_MAX;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        pq.push({0, src, 0});
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            if(cur[2] <=k+1 && cur[1] == dst) ans = min(ans, cur[0]);
            for(auto nxt: g[cur[1]]){
                if(cur[2] <=k && cost[nxt.first][cur[2]+1] > cur[0] + nxt.second){
                    cost[nxt.first][cur[2]+1] = cur[0]+nxt.second;
                    pq.push({cost[nxt.first][cur[2]+1], nxt.first, cur[2]+1});
                }
            }
        }
        return ans == INT_MAX? -1 : ans;
    }
};