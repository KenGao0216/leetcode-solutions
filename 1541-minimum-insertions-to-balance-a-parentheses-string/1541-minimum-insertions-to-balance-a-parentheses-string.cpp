class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        stack<int>st;
        for(char c:s){
            if(c== '(') {
                if(!st.empty() && st.top() == 1) {ans++; st.pop();}
                st.push(2);
            }
            else{
                if(st.empty()){
                    ans++;
                    st.push(2);
                }
                st.top()--;
                if(st.top() == 0) st.pop();
            }
        }
        while(!st.empty()) {ans+=st.top(); st.pop();}
        return ans;
    }
};