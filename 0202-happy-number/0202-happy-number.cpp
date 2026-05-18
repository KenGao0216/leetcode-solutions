class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int>m;
        int x = n;
        while(true){
            x = f(x);
            if(x==1) return true;
            if(m[x]) break;
            m[x] = 1;
        }
        return false;
    }

    int f(int n){
        int ans = 0;
        while(n>0){
            ans+= (n%10) * (n%10);
            n/=10;
        }
        return ans;
    }
};