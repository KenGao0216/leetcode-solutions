class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        string cur;
        int cnt = 0;
        bool is = false;
        for(char c:s){
            if(c=='('){
                cnt++;
                cur.push_back(c);
            }
            else {
                cnt--;
                cur.push_back(c);
                if(cnt == 0){
                    if(cur.length() >2) ans+=cur.substr(1, cur.length()-2);
                    cur.clear();
                }
            }
        }
        return ans;
    }
};