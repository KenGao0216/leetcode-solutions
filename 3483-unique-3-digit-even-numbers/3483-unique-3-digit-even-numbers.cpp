class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int>s;
        for(int i = 0; i<digits.size(); ++i){
            for(int j = 0; j<digits.size(); ++j){
                for(int k = 0; k<digits.size(); ++k){
                    if(digits[i]!= 0 && digits[k] %2==0 && i!=j && j!=k && i!=k) s.insert(100*digits[i]+10*digits[j]+digits[k]);
                }
            }
        }
        return s.size();
    }
};