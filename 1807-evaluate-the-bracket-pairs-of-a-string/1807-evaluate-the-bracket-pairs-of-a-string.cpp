class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>m;
        for(vector v:knowledge)    m[v[0]] = v[1];
        
        //for(auto [x,y]: m) cout<<x<<" "<<y<<endl;
        string ans = "";
        int n =s.length();
        int i = 0;
        while(i<n){
            if(s[i] == '('){
                int end = s.find(")", i);
                ans+= (m.count(s.substr(i+1, end-i-1))) ? m[s.substr(i+1, end-i-1)] : "?";
                i = end+1;
            }
            else {
                ans+=s[i];
                ++i;
            }
        }
        return ans;
    }
};