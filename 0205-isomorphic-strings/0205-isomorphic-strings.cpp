class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>m;
        unordered_map<char, char>m2;
        for(int i = 0; i<s.length(); ++i){
            if(m.count(s[i]) ==0) m[s[i]] = t[i];
            if(m2.count(t[i])== 0) m2[t[i]] = s[i];
            if(m[s[i]] != t[i] || m2[t[i]] != s[i]) return false;
            
        }
        return true;
    }
};