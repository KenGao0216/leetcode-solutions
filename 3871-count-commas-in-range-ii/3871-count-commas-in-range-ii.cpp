class Solution {
public:
    long long countCommas(long long n) {
        cout<<(n == 1LL*1e16);
        if(n < 1000) return 0;
        else if(n <1000000) return n-999;
        else if(n < 1000000000) return 1LL*2*(n-999999) + 999000;
        else if(n < 1000000000000) return 1LL*3*(n-999999999) + 1LL*2*999000000 + 999000;
        else return 1LL*4*(n-999999999999) + 1LL*3*999000000000 + 1LL*2*999000000 + 999000 + ((n == 1LL*1e15) ? 1: 0);
        
    }
};