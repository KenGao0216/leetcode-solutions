class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        map<long long,long long>m;
        m[0] = 0;
        for(int i = 0; i<nums1.size(); ++i) m[abs(nums1[i] - nums2[i])]++;
        
        auto it = prev(m.end());
        long long k = (long long)k1+k2;
        while (k > 0 && it != m.begin()) {
            long long v = it->first;
            long long y = it->second;             
            long long x = v - prev(it)->first;
            if (k >= x*y) {
                k -=x*y;
                auto lower = prev(it);
                lower->second += y;
                m.erase(it);
                it = lower;
            } else {
                long long full = k / y;
                long long rem  = k % y;
                m.erase(it);
                m[v-full] += y-rem;
                m[v-full-1] += rem;
                break;
            }
        }

        long long ans = 0;
        for (auto& [d, c] : m) ans += d * d * c;
        return ans;
    }
};

//5 9
// 10 17
//k = 57
//5 9
//6 6
//7 11
