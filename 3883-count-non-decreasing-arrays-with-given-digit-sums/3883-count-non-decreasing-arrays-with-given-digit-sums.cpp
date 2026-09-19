class Solution {
public:
    int countArrays(vector<int>& digitSum) {
        int n = digitSum.size();
        const int mod = 1e9+7;
        vector<int>m(5001);
        for(int i = 0; i<=5000; ++i){
            int x = i;
            int cur = 0;
            while(x>0) {
                cur += x%10;
                x/=10;
            }
            m[i] = cur;
        }
        vector<int>pre(5001), cur(5001);
        for(int i = 0; i<=5000; ++i) pre[i] = (m[i] == digitSum[0]);
        for(int i = 1; i<n; ++i){
            int x =0;
            for(int j = 0; j<=5000; ++j){
                x = (x+pre[j]) % mod;
                cur[j] = (m[j] == digitSum[i])? x : 0;
            }
            swap(pre, cur);
        }
        int ans = 0;
        for(int i: pre) ans = (ans+i)%mod;
        return ans;
    }
};