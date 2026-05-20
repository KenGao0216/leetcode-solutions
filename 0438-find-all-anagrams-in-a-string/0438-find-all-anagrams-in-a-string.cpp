class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.length() < p.length()) return {};
        vector<int>ms(26,0);
        vector<int>mp(26,0);
        for(int i = 0; i<p.length(); ++i) {
            ms[s[i]-'a']++;
            mp[p[i]-'a']++;
        }
        vector<int>ans;
        for(int i = 0; i<=s.length()-p.length(); ++i){
            if(ms==mp) ans.push_back(i);
            ms[s[i]-'a']--;
            if(i+p.length() < s.length()) ms[s[i+p.length()]-'a']++;
        }
        return ans;
    }
};