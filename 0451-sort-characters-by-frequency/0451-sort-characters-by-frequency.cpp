class Solution {
public:
    string frequencySort(string s) {
        map<char, int>m;
        map<int, vector<char>, greater<int>>f;
        for(char c:s){
            m[c]++;
        }
        for(auto [x,y]:m) f[y].push_back(x);
        string ans = "";
        for(auto [x,y]:f){
            for(char c:y) ans.append(x,c); 
        }
        return ans;
    }
};