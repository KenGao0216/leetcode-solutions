class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>>g(n);
        for(int i = 0; i<manager.size(); ++i) if(manager[i] != -1) g[manager[i]].push_back(i);
        int ans = 0;
        queue<pair<int,int>>q;
        q.push({headID, informTime[headID]});
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            ans = max(ans, cur.second);
            for(int nxt:g[cur.first]){
                q.push({nxt, informTime[nxt] + cur.second});
            }
        }
        return ans;
    }
};