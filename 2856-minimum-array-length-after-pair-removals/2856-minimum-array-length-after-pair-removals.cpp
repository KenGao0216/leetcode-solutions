class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int maxi = 0, tot = 0, cur = nums[0], cnt = 1;
        for(int i = 1; i<nums.size(); ++i){
            if(nums[i] == cur) cnt++;
            else{
                maxi = max(maxi, cnt);
                cur = nums[i];
                cnt = 1;
            }
        }
        maxi = max(maxi, cnt);
        
        return max((int) nums.size()%2, (int) (2*maxi - nums.size()));
    }
};
