class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char>st;
        int id = 0;
        while(id<num.length() && k>0){
            //cout<<id<<" "<<k<<"\n";
            while(!st.empty() && st.back() > num[id] && k>0){
                st.pop_back();
                k--;
            }
            st.push_back(num[id]);
            id++;
            
        }
        st.resize(st.size()-k);
        while(id<num.length()) {st.push_back(num[id]); ++id;}
        if(st.empty()) return "0";
        int i = 0;
        while(i<st.size() && st[i] == '0') ++i;
        return st.size() == i? "0": string(st.begin()+i, st.end());
    }
};