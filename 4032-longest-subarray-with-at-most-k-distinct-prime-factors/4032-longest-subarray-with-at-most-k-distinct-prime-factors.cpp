class Solution {
public:
    static constexpr int MAX = 1e5+1;
    static vector<vector<int>>& PF() {
        static vector<vector<int>> pf = [] {
            vector<vector<int>> pf(MAX);
            for (int i = 2; i < MAX; ++i) {
                if (pf[i].empty()) {
                    for (int j = i; j < MAX; j += i) pf[j].push_back(i);
                }
            }
            return pf;
        }();
        return pf;
    }

    int longestSubarray(vector<int>& nums, int k) {
        auto& pf = PF();
        int ans = 0;
        int l = 0, r = 0;
        vector<int>m(MAX, 0);
        int dist = 0;
        while(r<nums.size() && l<=r){
            for(int x:pf[nums[r]]) if(m[x]++ == 0) dist++;
            // for(auto [x,y]:m) cout<<x<<" "<<y<<"\n";
            // cout<<"-------"<<m.size()<<"--------\n";
            if(dist <= k) ans = max(ans, r-l+1);
            else{
                while(dist > k){
                for(int x:pf[nums[l]]) if(--m[x] == 0) dist--;
                l++;
                }
            }
            r++;

        }
        return ans;
    }
};