class Solution {
public:
    int ans;
    int countArrangement(int n) {
        vector<int>v(n+1);
        iota(v.begin(), v.end(), 0);
        f(1, n, v);
        return ans;
    }
    void f(int pos, int n, vector<int>&v){
        if(pos > n){
            ans++;
            return;
        }
        for(int i = pos; i<=n; ++i){
            swap(v[pos], v[i]);
            if(v[pos] % pos == 0 || pos%v[pos] == 0) f(pos+1, n, v);
            swap(v[pos], v[i]);
        }
    }
};