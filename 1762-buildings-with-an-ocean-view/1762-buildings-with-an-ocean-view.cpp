class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();
        vector<int>suf(n+1);
        vector<int>ans;
        for(int i = n-1; i>=0; --i) suf[i] = max(suf[i+1], heights[i]);
        for(int i = 0; i<n; ++i) if(heights[i] > suf[i+1]) ans.push_back(i);

        return ans;
    }
};