class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        while(n > 0){
            if((n & 1) == 0) {//..10
                n/=2;
            }
            else {
                if(n==1 || ((n&3) == 1)) n--;
                else n++; 
                ans++;
            }
        }
        return ans;

    }
};

// 100111

// 110110

//0 0 0 0 0 0 0 0 1 1 0 1 1 0 0 1 1 0
//0 1 2 3 4 5 6 7 8 9 1011121314151617