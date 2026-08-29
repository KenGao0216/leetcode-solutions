class Solution {
public:
    vector<int>par;
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int>vals = nums;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        int k = vals.size();
        par.resize(k);
        iota(par.begin(), par.end(), 0);
        for(int i = 0; i<k-1; ++i) {
            if(vals[i+1] - vals[i] <= limit) unio(i, i+1);
        }
        unordered_map<int,int>rank;
        for(int i = 0; i<k; ++i){
            rank[vals[i]] = i;
        }
        unordered_map<int, vector<int>>m;
        vector<int>ans = nums;
        for(int i = 0; i<nums.size(); ++i){
            int godpar = find(rank[nums[i]]);
            m[godpar].push_back(i); 
        }
        for(auto &[x,y]:m){
            vector<int>ids = y;
            sort(ids.begin(), ids.end());
            vector<int>vs;
            for(int i:ids) vs.push_back(nums[i]);
            sort(vs.begin(), vs.end());
            for(int i = 0; i<vs.size(); ++i){
                ans[ids[i]] = vs[i];
            }
        }


        return ans;
    }

    int find(int a){
        if(par[a]== a) return a;
        return par[a] = find(par[a]);
    }

    void unio(int a, int b){
        int pa = find(a);
        int pb = find(b);
        if(pa!=pb) par[pb] = pa;
    }
};