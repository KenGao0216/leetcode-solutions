class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, h = *max_element(nums.begin(), nums.end())+1;
        int ans = INT_MAX;
        while(l<=h){
            int m = (l+h)/2;
            int sum = 0;
            for(int i:nums) sum+= i%m == 0 ? i/m : i/m + 1;
           // cout<<m<<": "<<sum<<"\n";
            if(sum<=threshold) {
                ans = min(ans, m);
                h = m-1; 
            }
            else l = m+1;
        }
        return ans;
    }
};