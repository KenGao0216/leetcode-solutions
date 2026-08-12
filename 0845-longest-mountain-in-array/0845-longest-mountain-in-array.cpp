class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if(n==1) return 0;
        int ans = 0;
        int up = 1;
        int down = 1;
        int i = 1;
        while(i<n){
            while(i<n && arr[i] > arr[i-1]) {up++; i++;}
            if(up>1){
                while( i< n && arr[i] < arr[i-1]) {down++; i++;}
                if(down>1) {
                    ans = max(ans, up+down-1);
                    --i;
                }
            }
            down=1;
            up = 1;
            ++i;
        }
        return ans == 1? 0 :ans;
    }
};

