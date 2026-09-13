class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int,int>>co2;
        vector<pair<int,int>>co1;
        int n = img1.size();
        for(int i = 0; i<n; ++i){
            for(int j = 0; j<n;++j){
                if(img1[i][j] == 1) co1.push_back({i, j});
                if(img2[i][j] == 1) co2.push_back({i,j});
            }
        }
        int ans = 0;
        map<pair<int,int>, int>m;
        for(int i = 0; i<co1.size(); ++i){
            int x = co1[i].first, y = co1[i].second;
            int cnt = 0;
            for(int j = 0; j<co2.size(); ++j){
                pair<int,int> p = {co2[j].first-x, co2[j].second-y};
                m[p]++;
                cnt = max(cnt, m[p]);
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};