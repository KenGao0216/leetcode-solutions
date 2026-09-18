class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<pair<int,int>>v;
        vector<int>first(26, -1), last(26, -1);
        for(int i = 0; i<n; ++i)   {
            char c = s[i]-'a';
            if(first[c] == -1) first[c] = i;
            last[c] = i;
        }

        for(int i = 0; i<n; ++i){
            int start = i, end = last[s[i]-'a'];
            bool is = true;
            for(int j = i; j<=end; ++j){
                int c = s[j]-'a';
                if(first[c] < start) {is = false; break;}
                end = max(end, last[c]);
            }
            if(is) v.push_back({start, end});
        }
        sort(v.begin(), v.end(), [](const pair<int,int>a, const pair<int,int>b){
            if(a.second == b.second) return a.first > b.first;
            return a.second < b.second;
        });

        //for(auto x:v) cout<<"("<<x.first<<","<<x.second<<") ";
        vector<string>ans;
        int end = 0;
        for(int i= 0; i<v.size(); ++i){
            if(v[i].first >=end){ 
                string str = s.substr(v[i].first, v[i].second-v[i].first+1);
                ans.push_back(str);
                end = v[i].second;
            }
        }
        return ans.size()==0 ?  vector<string>{s} : ans;
        
    }
};