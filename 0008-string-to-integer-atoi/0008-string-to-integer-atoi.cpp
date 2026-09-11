class Solution {
public:
    int myAtoi(string s) {
       int i = 0;
       int n = s.length();
       while(i<n && s[i] == ' ') ++i;
       int sign;
       if(s[i] == '-') sign = -1;
       else sign = 1;
       if(i<n && s[i]=='-' || s[i] == '+') i++;
       while(i<n && s[i] == '0') ++i;
       long long num = 0;
       while(i<n && s[i] >= '0' && s[i] <='9') {
            long long x = s[i] - '0';
            num = 10*num + x;
            if(sign == 1 && num > INT_MAX) return INT_MAX;
            if(sign == -1 && num > 1LL*INT_MAX + 1) return INT_MIN;
            ++i;
       }

        return sign*num;
       
    }
};