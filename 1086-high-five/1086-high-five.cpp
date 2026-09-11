class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
       map<int,vector<int>>m;
        for(vector i:items){
            m[i[0]].push_back(i[1]);
        }
        vector<vector<int>>ans;
        for(auto &[x,y]:m){
            sort(y.begin(), y.end());
            int n = y.size();
            int tot = (y[n-1] + y[n-2] + y[n-3]+y[n-4]+y[n-5])/5;
            ans.push_back({x,tot});
        }
        return ans;
    }
};