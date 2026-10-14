class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > 9 *num) return "";
        int x = sum / 9;
        string ans(x, '9');
        if(num == x) return ans;
        ans+=char('0' + sum%9);
        ans.append(num - x-1, '0');
        return ans;
    }
};