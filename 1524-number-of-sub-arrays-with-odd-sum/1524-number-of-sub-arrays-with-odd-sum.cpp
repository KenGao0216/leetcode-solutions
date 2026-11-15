class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int o = 0, e= 1;
        long ans = 0;
        int mod = 1e9+7;
        int sum = 0;
        for(int i = 0; i<arr.size(); ++i){
            sum+=arr[i];
            if(sum%2==0) {ans= (ans + o)%mod; e++;}
            else {ans= (ans+e)%mod; o++;}
        }
        return ans;
    }
};