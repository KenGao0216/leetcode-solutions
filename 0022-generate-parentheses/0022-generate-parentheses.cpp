class Solution {
public:
vector<string>ans;
    vector<string> generateParenthesis(int n) {
        f(n, 0, 0, "");
        return ans;
    }
    void f(int n, int o, int c, string path){
           if(o < c || o>n || c>n) return;
            if(o==n && c == n) {ans.push_back(path); return;}
            path+='(';
            f(n, o+1, c, path);
            path.pop_back();
            path+=')';
            f(n, o, c+1, path);
            path.pop_back();
    }
};