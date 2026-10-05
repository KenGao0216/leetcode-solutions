class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        for(char c:s){
            if(c=='(') st.push(0);
            else{
                int v = (st.top() == 0 )? 1 : 2*st.top();
                st.pop();
                if(!st.empty()) st.top()+=v;
                else st.push(v);
            }
        }
        return st.top();
    }
};