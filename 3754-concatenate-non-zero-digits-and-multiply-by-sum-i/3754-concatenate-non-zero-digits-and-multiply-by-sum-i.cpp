class Solution {
public:
    long long sumAndMultiply(int n) {
        int x = 0;
        int div = 1, sum = 0;
        while(n>0){
            if(n%10 != 0) {
                x = div*(n%10)+x;
                div*=10;
                sum+=n%10;
            }
            n/=10;
        }
        return 1LL*x*sum;
    }
};