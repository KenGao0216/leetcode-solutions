class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>diff(n+2, 0);
        for(vector b:bookings){
            int s = b[0], e = b[1], x = b[2];
            diff[s]+=x;
            diff[e+1]-=x;
        }
        for(int i = 1; i<=n; ++i) diff[i] +=diff[i-1];
        return vector<int>(diff.begin()+1, diff.end()-1);
    }
};