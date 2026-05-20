class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        vector<string>parts = split(path);
        for(string &i: parts){
            if(i == ".") continue;
            else if(i==".."){
                if(!st.empty()) st.pop();
            }
            else st.push(i);
        }
        vector<string>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        string res = "";
        for(int i = 0; i<(int)ans.size(); ++i){
            res+="/"+ans[i];
        }
        return res.empty()? "/":res;
    }
    vector<string>split(string path){
        vector<string>res;
        string cur = "";
        for(int i = 0; i<(int)path.size(); ++i){
            if(path[i] == '/'){
                if(!cur.empty()) res.push_back(cur);
                cur = "";
            }
            else cur+=path[i];
        }
        if(!cur.empty()) res.push_back(cur);
        return res;
    }
};