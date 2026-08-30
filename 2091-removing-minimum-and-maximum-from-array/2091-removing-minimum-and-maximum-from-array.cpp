class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxi = -1e5, max_id, mini = 1e5, min_id;
        for(int i = 0; i<nums.size(); ++i){
            if(nums[i]>maxi){
                maxi = nums[i];
                max_id = i;
            }
            if(nums[i] < mini){
                mini = nums[i];
                min_id = i;
            }
        }
        cout<<min_id<<" "<<max_id<<"\n";
        if(min_id > max_id) swap(min_id, max_id);
        cout<<min_id<<" "<<max_id<<"\n";
        return min((int)nums.size() - (max_id-min_id-1), min((int)nums.size()-min_id, max_id+1));
    }
};

// -14,61,29,-18,59,13,-67,-16,55,-57,7,74
// 0   1   2  3  4  5   6  7    8  9  10  11