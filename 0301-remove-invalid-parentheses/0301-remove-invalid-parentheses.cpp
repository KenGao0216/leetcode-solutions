class Solution {
public:
    unordered_set<string>st;
    vector<string> removeInvalidParentheses(string s) {
        int l = 0, r = 0;
        for(char c:s){
            if(c=='(') l++;
            else if(c==')'){
                if(l > 0) l--;
                else r++;
            }
        }
        string path;
        f(s, 0, l, r, 0, path);
        return vector<string>(st.begin(), st.end());
    }
    void f(string &s, int i, int l, int r, int o, string &path){
        if(i== s.length()) {
            if(l==0 && r==0 && o==0) st.insert(path);
            return;
        }
        char c = s[i];
        if(c=='(' && l > 0) f(s, i+1, l-1, r, o, path);
        else if(c==')' && r > 0) f(s, i+1, l, r-1, o, path);
        path.push_back(c);
        if(c=='(') f(s, i+1, l, r, o+1, path);
        else if(c==')'){
            if(o > 0) f(s, i+1, l, r, o-1, path);
        }
        else f(s, i+1, l, r, o, path);
        path.pop_back();

    }
};