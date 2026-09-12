class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long>pre(n+1, 0);
        for(int i = 1; i<=n; ++i) pre[i] = pre[i-1]+nums[i-1];
        
        int l = 1, r = n;
        int ans = 1;
        while(l<=r){
            int m = (l+r) / 2;
            long long x = f(nums, pre,m, n);
            if(x<=k){
                ans = max(ans, m);
                l = m+1;
            }
            else r = m-1;
        }
        return ans;
        
    }

    int f(vector<int>& nums, vector<long long>&pre, int freq, int n){
        long long mini = INT_MAX;
        for(int i = freq-1; i<n; ++i){
            long long cur = 1LL* freq*nums[i] - (pre[i+1] - pre[i-freq+1]);
            mini = min(mini, cur);
        }
        return mini;
    }
};

// 1 4 8 13
// 0 1 2 3

// 0 1 2 3 4
// 0 1 5 13 26