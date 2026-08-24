class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>g(n+1);
        vector<int>label(n+1,0);
        for(auto i:dislikes){
            int a = i[0], b = i[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        for(int i = 1; i<=n; ++i){
            if(!label[i]){
                queue<int>q;
                q.push(i);
                label[i] = 1;
                while(!q.empty()){
                    int cur = q.front();
                    q.pop();
                    for(int nxt:g[cur]){
                        if(label[nxt] == label[cur]) return false;
                        if(label[nxt] == 0) {
                            label[nxt] = 3-label[cur];
                            q.push(nxt);
                        }
                    }
                }
            }
        }
        return true;
    }
};