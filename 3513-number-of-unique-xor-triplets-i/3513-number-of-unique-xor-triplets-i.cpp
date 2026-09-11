class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return n;
        int x = 2;
        while(x<=n) x*=2;
        return x;
    }
};