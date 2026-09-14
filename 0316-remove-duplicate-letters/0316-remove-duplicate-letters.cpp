class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>last(26);
        for(int i = 0; i<s.length(); ++i) last[s[i]-'a'] = i;
        string st;
        vector<bool>used(26, false);
        for(int i = 0; i<s.length(); ++i){
            if(used[s[i]-'a']) continue;
            while(!st.empty() && st.back() > s[i] && last[st.back()-'a'] > i){
                used[st.back()-'a'] = false;
                st.pop_back();
            }
            st.push_back(s[i]);
            used[s[i]-'a'] = true;
        }
        return st;
    }
};