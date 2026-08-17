class Solution {
public:
    int smallestNumber(int n, int t) {
        int ans =n;
        while(dp(ans) %t != 0) ans++;
        return ans;
    }
    int dp(int n){
        int prod = 1;
        while(n>=10){
            prod *= n%10;
            n/=10;
        }
        prod*=n;
        return prod;
    }
};