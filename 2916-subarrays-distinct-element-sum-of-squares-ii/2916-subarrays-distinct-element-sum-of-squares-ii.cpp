class Solution {
    static const long long MOD = 1e9+7;
    struct SegmentTree{
            int n;
            vector<long long>sum;
            vector<long long>sqsum;
            vector<long long> lazy;
            SegmentTree(int sz){
                n = sz;
                sum.assign(4*n, 0);
                sqsum.assign(4*n, 0);
                lazy.assign(4*n, 0);
            }

            void apply(int node, int l, int r, long long val){
                long long len = r-l+1;
                sqsum[node] = (sqsum[node]+1LL*2*val % MOD * sum[node]%MOD + len%MOD *val%MOD * val%MOD)%MOD;
                sum[node] = (sum[node] + len%MOD *val) % MOD;
                lazy[node] = (lazy[node]+val)%MOD;
            }
            void push(int node, int l, int r){
                if(l==r) return;
                if(lazy[node] == 0) return;
                int mid = l + (r-l)/2;
                apply(node*2, l, mid, lazy[node]);
                apply(node*2+1, mid+1, r, lazy[node]);
                lazy[node] = 0;
            }

            void rangeAdd(int node, int l, int r, int qL, int qR, long long val){
                if(qR <l || r < qL) return;
                if(qL<=l && r<=qR){
                    apply(node, l, r, val); 
                    return;
                }
                push(node, l, r);
                int mid = l+(r-l)/2;
                rangeAdd(node*2, l, mid, qL, qR, val);
                rangeAdd(node*2+1, mid+1, r, qL, qR, val);
                sum[node] = (sum[node*2] + sum[node*2+1])%MOD;
                sqsum[node] = (sqsum[node*2]+sqsum[node*2+1])%MOD;
            }

    };
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        SegmentTree tree(n);
        unordered_map<int,int>last;
        long long ans= 0;
        for(int r = 0; r<n; ++r){
            int val = nums[r];
            int prev = -1;
            if(last.count(val)) prev = last[val];
            tree.rangeAdd(1, 0, n-1, prev+1, r, 1);
            last[val] = r;
            ans = (ans+tree.sqsum[1])%MOD;
        }

        return ans;
    }
};