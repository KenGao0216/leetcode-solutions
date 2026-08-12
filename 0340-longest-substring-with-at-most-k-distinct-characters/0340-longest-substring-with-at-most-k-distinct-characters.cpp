class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int ans = 0;
        unordered_map<char,int>m;
        int l = 0, r = 0;
        while(l<=r && r<s.length()){
            m[s[r]]++;
            if(m.size() <=k) ans = max(ans, r-l+1);
            else{
                m[s[l]]--;
                if(m[s[l]] == 0) m.erase(s[l]);
                l++;
            }
            r++;
        }
        return ans;
    }
};