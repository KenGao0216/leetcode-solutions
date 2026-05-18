class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int>rm;
        unordered_map<char, int>mm;
        for(char i: ransomNote) rm[i]++;
        for(char i:magazine) mm[i]++;
        for(auto [x,y]: rm) {
            if(mm[x] < y) return false;
        }
        return true;
    }
};