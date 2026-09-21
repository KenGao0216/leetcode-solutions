class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        stack<pair<int,long long>>st2; //{index, sum};
        vector<long long>suf(n+1);
        for(int i = n-1; i>=0; --i){
            while(!st2.empty() && maxHeights[st2.top().first] > maxHeights[i]) st2.pop();
            if(st2.empty()) suf[i] = 1LL*(n-i)*maxHeights[i];
            else suf[i] = st2.top().second + 1LL*maxHeights[i]*(st2.top().first-i);
            st2.push({i, suf[i]});
        }

        stack<pair<int, long long>>st;
        long long pre = 0;
        long long ans = 0;  
        for(int i = 0; i<n; ++i){
            while(!st.empty() && maxHeights[st.top().first] > maxHeights[i]) st.pop();
            if(st.empty()) st.push({i, 1LL*(i+1)*maxHeights[i]});
            else st.push({i, st.top().second + 1LL*maxHeights[i]*(i-st.top().first)});
            pre = st.top().second;
            ans = max(ans, suf[i] + pre - maxHeights[i]);
        }      
        return ans;

    }
};

// {5,5}
// {3,6}
// {4,10}, {3,6}
// {1,4}
// {1,5}, {1,4}


// {1,1}
// {1,2}, {1,1}
// {4, 6}, {1,2}, {1,1}
// {3, 8}, {1,2}, {1,1}
// {5, 13}, {3, 8}, {1,2}, {1,1}
