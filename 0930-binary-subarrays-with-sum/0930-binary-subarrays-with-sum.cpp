class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int l = 0, r = 0;
        int n = nums.size();
        int ans = 0;
        int sum = 0;
        unordered_map<int, int>m;
        m[0] = 1;
        for(int i = 0; i<n; ++i){
            sum+=nums[i];
            if(m.count(sum-goal)) ans+=m[sum-goal];
            m[sum]++;
        }
        //for(auto [x,y]:m) cout<<x<<" "<<y<<"\n";
        return ans;
    }
};