class Solution {
public:
    bool isHappy(int n) {
        int s = n, f = n;
        s = fun(s), f = fun(fun(f));
        while(s!=f){
            s = fun(s);
            f = fun(fun(f));
        }

        return s == 1;
    }

    int fun(int n){
        int ans = 0;
        while(n>0){
            ans+= (n%10) * (n%10);
            n/=10;
        }
        return ans;
    }
};