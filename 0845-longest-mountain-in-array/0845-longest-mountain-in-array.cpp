class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if(n==1) return 0;
        vector<int>lis(n, 0);
        vector<int>lds(n, 0);
        int x = arr[0];
        int len = 1;
        for(int i = 1; i<n; ++i){
            if(arr[i] > x){
                x = arr[i];
                len++;
                lis[i] = len;
            }
            else{
                len = 1;
                x = arr[i];
            }
        }
        x = arr[n-1];
        len = 1;
        for(int i = n-2; i>=0; --i){
            if(arr[i] > x){
                x = arr[i];
                len++;
                lds[i] = len;
            }
            else{
                len = 1;
                x = arr[i];
            }
        }
        int ans = 0;
        for(int i = 0; i<n; ++i) {
            if(lis[i] > 0 && lds[i] > 0) ans = max(ans, lis[i]+lds[i]-1);
        }
        return ans;
    }
};

