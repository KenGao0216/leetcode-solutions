class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int l = 0, r= 0; 
        int n = nums.size();
        int tot = 0;
        for(int i:nums) tot+=i;
        int sum = 0;
        int ans = INT_MAX;
        cout<<"tot: "<<tot<<endl;
        if(tot < x) return -1;
        while(r<n){
            if(sum == tot-x)  {
                ans = min(ans, n-(r-l));
                sum+=nums[r];
                ++r;
            }
            else if(sum > tot-x) {sum-=nums[l]; ++l;}
            else { sum+=nums[r]; ++r; }
        }
        while(sum > tot-x) {sum-=nums[l]; ++l;}
        if(sum == tot-x) ans = min(ans, n-(r-l));
        return ans == INT_MAX? -1: ans;
    }
};