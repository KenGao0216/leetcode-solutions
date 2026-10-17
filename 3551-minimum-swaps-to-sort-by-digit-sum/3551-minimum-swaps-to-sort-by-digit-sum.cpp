class Solution {
public:
    int minSwaps(vector<int>& nums) {

        vector<int>ds;
        for(int i:nums) ds.push_back(f(i));
        vector<int> idx(nums.size());
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            if (ds[i] != ds[j]) return ds[i] < ds[j];
            return nums[i] < nums[j];
        });
        vector<int>vis(nums.size(), false);
        int c = 0;
        for(int i = 0; i<nums.size(); ++i){
            if(vis[i]) continue;
            c++;
            int j = i;
            while(!vis[j]){
                vis[j] = true;
                j = idx[j];
            }
        }
        return nums.size()-c;
    }
    int f(int i){
        int ans = 0;
        while(i>0){
            ans+=i%10;
            i/=10;
        }
        return ans;
    }

};
