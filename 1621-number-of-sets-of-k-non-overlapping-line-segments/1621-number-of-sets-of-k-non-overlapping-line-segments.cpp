class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9+7;
        vector<long long>open(k+1), closed(k+1);
        closed[0] = 1;
        for(int i = 0; i<n; ++i){
            vector<long long> nopen(k+1), nclosed(k+1);
            for(int j = 0; j<=k; ++j){
                nclosed[j] = (nclosed[j]+ closed[j]) % MOD;
                nopen[j] = (nopen[j] + closed[j]) % MOD;
                nopen[j] = (nopen[j] + open[j]) % MOD;
                if(j > 0){
                    nclosed[j] = (nclosed[j] + open[j-1]) % MOD;
                    nopen[j] = (nopen[j] + open[j-1]) % MOD;
                }
               

            }
             closed = nclosed;
                open = nopen;
        }
        return closed[k];
    }
};

