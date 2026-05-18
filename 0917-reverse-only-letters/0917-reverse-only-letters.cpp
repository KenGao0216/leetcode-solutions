class Solution {
public:
    string reverseOnlyLetters(string s) {
        int l = 0, r = s.length()-1;
        while(l<r){
            while(!isalpha(s[l]) && l<r) l++;
            while(!isalpha(s[r]) && l<r) r--;
            if(isalpha(s[l]) && isalpha(s[r])) swap(s[r], s[l]);
            l++;
            r--;
        }
        return s;
    }
};