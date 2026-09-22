class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int l = 0, r = nums1.size();
        int tot = (nums1.size() + nums2.size()+1)/2;
        bool isE = (nums1.size() + nums2.size()) % 2;
        while(l<=r){
            int m = (l+r)/2;
            int j = tot-m;
            int a_left = (m==0)? INT_MIN : nums1[m-1];
            int a_right = (m==nums1.size())? INT_MAX : nums1[m];
            int b_left = (j==0)? INT_MIN :nums2[j-1];
            int b_right = (j==nums2.size())? INT_MAX: nums2[j];

            if(a_left <= b_right && a_right >= b_left) {
                if(!isE) return (max(a_left, b_left) + min(a_right, b_right)) / 2.0;
                else return (double) max(a_left, b_left);
            }
            if(a_left > b_right) r = m-1;
            else l = m+1;
        }
        return 0;

    }
};