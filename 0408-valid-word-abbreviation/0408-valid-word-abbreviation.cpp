class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int idx = 0;
        string s = "";
        while(idx < abbr.size()){
            string slen = "";
            while(isdigit(abbr[idx])){
                slen+= abbr[idx];
                idx++;
            }
            if(slen.length()>0){
                if(slen[0] == '0' || s.length() + stoi(slen) > word.length()) return false;
                int len = stoi(slen);
                s+=string(len, '_');
            }
            else{
                s+=abbr[idx];
                idx++;
            }
        }
        //cout<<s<<" ";
        //cout<<idx;
        for(int i = 0; i<word.length(); ++i){
            if(s[i] == '_') continue;
            else if(s[i] != word[i]) return false;
        }
        return s.length() == word.length();
        
    }
};