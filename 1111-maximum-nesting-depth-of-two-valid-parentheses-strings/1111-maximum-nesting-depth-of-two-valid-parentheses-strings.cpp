class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int a = 0, b = 0;
        int n = seq.length();
        vector<int>ans(n);
        for(int i = 0; i<n; ++i){
            char c = seq[i];
            if(c=='('){
                if(a<=b){
                    a++;
                    ans[i] = 0;
                }
                else {
                    b++;
                    ans[i] = 1;
                }
            }
            else{
                if(a<b) {b--; ans[i] = 1;}
                else {a--; ans[i] = 0;}
            }
        }
        return ans;
    }
};