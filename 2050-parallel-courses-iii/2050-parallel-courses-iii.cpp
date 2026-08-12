class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int>in(n+1,0);
        vector<vector<int>>g(n+1);
        for(const auto& v: relations){
            g[v[0]].push_back(v[1]);
            in[v[1]]++;
        }
        vector<int>ans(n+1,0);
        queue<int>q;
        for(int i = 1; i<=n; ++i){
            if(in[i] == 0){
                ans[i] = max(ans[i], time[i-1]);
                q.push(i);
            }
        }
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int nxt: g[cur]){
                in[nxt]--;
                ans[nxt] = max(ans[nxt], time[nxt-1]+ans[cur]);
                if(in[nxt]==0){
                    q.push(nxt);
                }
            }
        }
        //for(int i:ans) cout<<i<<" ";
        return *max_element(ans.begin(),ans.end());
    }
};