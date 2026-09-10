class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        unordered_map<char, vector<int>>m;
        for(int i = 0; i<s.length(); ++i){
            m[s[i]].push_back(i);
        }
        vector<pair<int,int>>v;
        for(auto[x,y]:m){
            v.push_back({y[0], y.back()});
        }
        sort(v.begin(), v.end());
        int l = v[0].first, r = v[0].second;
        for(auto x:v){
            if(x.first >= l && x.first <= r && x.second > r){
                r = x.second;
            }
            else if(x.first > r) {
                ans.push_back(r-l+1);
                l = x.first;
                r = x.second;
            }
        }
        ans.push_back(r-l+1);
        return ans;
    }
};

//(0,8) (1,5) (4,7) (9,14) (10,15) (11,11) (13,13) (16,19) (17,22) (18,23) (20,20) (21,21) 