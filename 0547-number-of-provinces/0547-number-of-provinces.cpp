class Solution {
public:
    vector<int>par;
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = (int)isConnected.size();
        for(int i =0; i<n; ++i) par.push_back(i);
        for(int i = 0; i<n; ++i){
            for(int j = i; j<n; ++j){
                if(isConnected[i][j]) Union(i, j);
            }
        }
        unordered_set<int>s;
        for(int i = 0; i<n; ++i) s.insert(find(i));
        return (int)s.size();

    }

    int find(int a){
        if(par[a]!=a) par[a] = find(par[a]);
        return par[a];
    }
    void Union(int a, int b){
        int pa = find(a);
        int pb = find(b);
        if(pa!=pb) par[pb] = pa;
    }
};