class Solution {
public:
    vector<int>par;
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        par.resize(1e5+1);
        iota(par.begin(), par.end(), 0);
        for(int i = 0; i<n-1; ++i){
            if(abs(nums[i] - nums[i+1]) <= maxDiff) uni(nums[i], nums[i+1]);
        }
        vector<bool>ans;
        for(vector q:queries){
            if(find(nums[q[0]]) == find(nums[q[1]])) ans.push_back(true);
            else ans.push_back(false);
        }   
        return ans;
    }

    int find(int a){
        if(par[a] == a) return a;
        return par[a] = find(par[a]);
    }
    void uni(int a, int b){
        int pa = find(a), pb = find(b);
        if(pa!=pb){
            par[pb] = pa;
        }
    }
};