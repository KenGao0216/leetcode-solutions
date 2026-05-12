class Solution {
public:
    string convert(string s, int numRows){
        if(numRows==1)return s;
        int y= 0;
        vector<string>ans(numRows+2, "");
        int dir = 1;
        for(int i = 0; i<s.length(); ++i){
            ans[y]+=s[i];
            y+=dir;
            if(y==0 || y==numRows-1) dir = -dir;
        }
        //for(string i: ans) cout<<i<<"\n";
        string res = "";
        for(string i:ans) res+=i;
        return res;
    }
};