class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,vector<int>>m;
        int sum = 0;
        int ans = 0;
        m[0].push_back(-1);
        for(int i = 0; i<nums.size(); ++i){
            sum+=nums[i];
            if(m.count(sum-k)) ans+=m[sum-k].size();
            m[sum].push_back(i);

        }
        //for(auto [x,y]:m) cout<<x<<" "<<y.size()<<"\n";
        return ans;

    }
};