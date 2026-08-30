class Solution {
public:
    string similarRGB(string color) {
        unordered_map<int, string>m;
        m[0] = "00";  m[102] = "66";  m[204] = "cc";
        m[17] = "11"; m[119] = "77"; m[221] = "dd";
        m[34] = "22"; m[136] = "88"; m[238] = "ee";
        m[51] = "33"; m[153] = "99"; m[255] = "ff";
        m[68] = "44"; m[170] = "aa"; 
        m[85] = "55"; m[187] = "bb";
        string ans = "#";
        for(int i = 1; i<color.length(); i+=2){
            string cur = color.substr(i,2);
            int val = stoi(cur, nullptr, 16);
            int div = val/17;
            int v1 = div*17, v2 = (div+1)*17;
            if(abs(v1-val) < abs(v2-val)) ans+= m[v1];
            else ans+=m[v2];
        }
        return ans;
    }
};