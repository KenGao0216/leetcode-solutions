class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        // for(int &i:nums) i%=k;
        // vector<long long>dp(k);
        // vector<long long>ans(k);
        // for(int x:nums){
        //     int a = x%k;
        //     vector<long long>dp2(k);
        //     for(int i = 0; i<k; ++i) dp2[(i*a)%k] +=dp[i];
        //     dp2[a]+=1;
        //     dp = dp2;
        //     for(int i = 0; i<k; ++i) ans[i]+=dp[i];
        // }

        vector<vector<long long>>dp(nums.size(), vector<long long>(k));
        for(int i = 0; i<nums.size(); ++i){
            int a = nums[i]%k;
            for(int r = 0; r<k; ++r){
                if(i!=0) 
                {
                    dp[i][(r*a)%k] += dp[i-1][r];
                }
            }
            dp[i][a]++;
        }

        vector<long long>ans(k);
        for(int i = 0; i<nums.size(); ++i){
            for(int r = 0; r<k; ++r) ans[r]+=dp[i][r];
        } 
        return ans;       

    }
};
