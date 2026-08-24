class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>st;
        int id = 0;
        string ans = "";
        while(id<num.size() && k>0){
            cout<<id<<" "<<k<<"\n";
            while(!st.empty() && st.top() > num[id]-'0' && k>0){
                st.pop();
                ans = ans.substr(0, ans.length()-1);
                k--;
            }
            st.push(num[id]-'0');
            ans+=num[id];
            id++;
            
        }
        if(k>0){
            if(k>=ans.length()) return "0";
            else ans = ans.substr(0, ans.length()-k);
        }
        ans+=num.substr(id);
        if(ans.length() == 0) return "0";
        while(ans[0] == '0') ans = ans.substr(1);
        return ans.length() == 0? "0": ans;
    }
};