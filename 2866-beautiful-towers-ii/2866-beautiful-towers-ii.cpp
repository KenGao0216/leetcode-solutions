class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        vector<long long>left(n);
        stack<pair<long long,int>>st;
        for(int i = 0; i<n; ++i){
            while(!st.empty() && st.top().first>maxHeights[i]) st.pop();
            if(!st.empty()) left[i] = left[st.top().second] + 1LL*(i-st.top().second)*maxHeights[i];
            else left[i] = 1LL*maxHeights[i] * (i+1);
            st.push({maxHeights[i], i});
        }
        while(!st.empty()) st.pop();
        vector<long long>right(n);
        for(int i = n-1; i>=0; --i){
            while(!st.empty() && st.top().first>maxHeights[i]) st.pop();
            if(!st.empty()) right[i] = right[st.top().second] + 1LL*(st.top().second-i)*maxHeights[i];
            else right[i] = 1LL*maxHeights[i] * (n-i);
            st.push({maxHeights[i], i});
        }

        // for(long long i:left) cout<<i<<" ";
        // cout<<endl;
        // for(long long i:right) cout<<i<<' ';
        // cout<<endl;
        long long ans = 0;
        for(int i = 0; i<n; ++i) ans = max(ans, right[i] + left[i] - maxHeights[i]);
        return ans;
    }
};
// 5 
// 3 3 = 6
// 3 3 4 = 10
// 1 1 1 1 = 4
// 1 1 1 1 1 = 5