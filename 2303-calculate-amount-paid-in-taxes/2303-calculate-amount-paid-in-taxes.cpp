class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double ans = 0;
        ans+=(double) min(brackets[0][0], income) * (double)brackets[0][1] / 100.00;
        for(int i = 1; i<brackets.size(); ++i){
            if(income < brackets[i-1][0]) break;
            ans+= (double) (min(brackets[i][0], income) - brackets[i-1][0]) * (double)brackets[i][1] / 100.00;
        }
        return ans;
    }
};