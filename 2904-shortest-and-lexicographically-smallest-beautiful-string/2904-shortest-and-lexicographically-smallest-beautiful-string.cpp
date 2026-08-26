class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int>v;
        for(int i = 0; i<s.length(); ++i) if(s[i] == '1') v.push_back(i);

        for(int i:v) cout<<i<<" ";
        int len = INT_MAX;
        string ans(s.length(), '1');
        if(v.size()<k) return "";
        for(int i = 0; i<v.size()-k+1; ++i){
            if(v[i+k-1] - v[i]+1 <=len){
                len = v[i+k-1]-v[i]+1;
                if(len< ans.length()) ans= s.substr(v[i], len);
                else if(len == ans.length())ans = min(ans,s.substr(v[i], len)); 
            }
        }
        //if("100011" < "11001") cout<<"YES";
        return ans;
    }
};