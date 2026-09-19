class Solution {
public:
    vector<string>ans;
    unordered_map<char, vector<char>> m = {
            {'2', {'a', 'b', 'c'}},
            {'3', {'d', 'e', 'f'}},
            {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}},
            {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}},
            {'9', {'w', 'x', 'y', 'z'}}
        };
    vector<string> letterCombinations(string digits) {
        string cur;
        f(0, digits, cur);
        return ans;
    }
    
    void f(int start, string s, string cur){
        if(cur.length() == s.length()) {
            ans.push_back(cur);
            return;
        }
            for(char c: m[s[start]]){
                cur+= c;
                f(start+1, s, cur);
                cur.pop_back();
            }
        
    }
};