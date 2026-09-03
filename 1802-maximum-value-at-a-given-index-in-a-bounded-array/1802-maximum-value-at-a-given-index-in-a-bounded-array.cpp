class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int l = 1, h = maxSum;
        int ans = 0, m; long long val;
        while(l<=h){
            m = (l+h)/2;
            val = f(index, m, n);
            if(val <= maxSum) {
                ans = max(ans, m);
                l = m+1;
            }
            else h = m-1;
            
        }
        return ans;
    }
    long long f(int index, int x, int n){
        long long sum = 0;
        if(x > index) sum+= 1LL*x*(index+1) - (1LL*index*(index+1))/2;
        else {
            int diff = index-x+1;
            sum+=(1LL*x*(x+1))/2 + diff;
        }
        index = n-index-1;
        if(x > index) sum+= 1LL*x*(index+1) - (1LL*index*(index+1))/2;
        else {
            int diff = index-x+1;
            sum+=(1LL*x*(x+1))/2 + diff;
        }
        return sum-x;
    }
};

//  x = 4
//index = 7
//n = 12
// 0 1 2 3 4 5 6 7 8 9 10 11 
// 1 1 1 1 1 2 3 4 3 2 1   1