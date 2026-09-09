class Solution {
public:
    string makeGood(string s) {
        int i = 0;
        while(!s.empty() && i<s.length()-1){
            cout<<i<<' ';
            if(s[i] != s[i+1] && (tolower(s[i]) == tolower(s[i+1]))){
                s = (i> 0? s.substr(0, i) : "") + (s.length() > 2 ? s.substr(i+2) : "");
                i--;
                if(i== -1) i = 0;
            }
            else ++i;
            //cout<<s<<"\n";
        }
        return s;
    }
};