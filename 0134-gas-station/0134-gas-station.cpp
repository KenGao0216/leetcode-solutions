class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int diff = 0;
        int ans = 0;
        int tank= 0;
        for(int i = 0; i<n; ++i){
            diff+=gas[i] - cost[i];
            tank+=gas[i]-cost[i];
            if(tank < 0) {
                ans = i+1;
                tank = 0;
            }
        }

        return diff < 0 ? -1 : ans;
    }
};