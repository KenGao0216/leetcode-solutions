class Solution {
public:
    bool isPalindromic(string s) {
        string ans = "";
        for(char c:s){
            int x = c;
            ans+=get_bit(x);
        }
        for(int i = 0; i<ans.length()/2; ++i){
            if(ans[i] != ans[ans.length()-i-1]) return false;
        }
        return true;
    }
    string get_bit(int x){
        string res="";
        int t = 128;
        while(t>0){
            int d = x/t;
            res+=to_string(d);
            x -=d*t;
            t/=2;
        }
        return res;
    }
};