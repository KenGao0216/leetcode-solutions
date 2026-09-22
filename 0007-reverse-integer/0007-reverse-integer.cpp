class Solution {
public:
    int reverse(int x) {
        if(x == 0) return 0;
        long long y = 0;
        while(x != 0){
            y = y*10 + x%10;
            x/=10;
            cout<<y<<" ";
            if(y>INT_MAX || y <INT_MIN) return 0;
        }
        return y;
    }
};