class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        map<char, int>s1;
        for(char i:s) s1[i]++;
        int last_best_id = -1; char last_best_char;
        int i = 0;
        map<char,int>freq_temp;
        for(; i<target.length(); ++i){
            char c = target[i];
            auto next_biggest = s1.upper_bound(c);
            if(next_biggest != s1.end()){
                last_best_id = i;
                last_best_char = next_biggest->first;
                freq_temp = s1;
            }
            auto c_count = s1.find(c);
            if(c_count == s1.end()) break;
            c_count->second--;
            if(c_count->second == 0) s1.erase(c_count);
        }
        if(last_best_id == -1) return "";
        string ans = target.substr(0, last_best_id) + last_best_char;
        freq_temp[last_best_char]--;
        if(freq_temp[last_best_char]==0) freq_temp.erase(last_best_char);

        for(auto [x,y]:freq_temp) ans+=string(y,x);

        return ans;
    }
};