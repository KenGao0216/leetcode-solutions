class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
        while(i < m+n && j<n){
            if(nums1[i] > nums2[j]){
                int tmp = nums1[i], tmp2;
                nums1[i] = nums2[j];
                for(int k = i+1; k<m+n; ++k){
                    tmp2 = nums1[k];
                    nums1[k] = tmp;
                    tmp = tmp2;
                }
                ++j;
            }
            else ++i;
        }
        for(int k = n-1; k>=j; --k){
            nums1[k+m] = nums2[k];
        }
        
    }
};