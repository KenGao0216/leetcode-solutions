class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int l = 0, r = 0;
        int ans = 0;
        unordered_map<char, int>m;
        while(l<=r && r<n){
            m[s[r]]++;
            while(m['a'] >0 && m['b'] > 0 && m['c'] > 0){
                ans+= n-r;
                m[s[l]]--;
                ++l;
            }
            ++r;
        }
        return ans;
    }
};