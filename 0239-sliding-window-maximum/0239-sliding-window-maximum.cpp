class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans;
        deque<pair<int,int>>q;
        for(int i = 0; i<k; ++i){
            while(!q.empty() && q.back().first < nums[i]) q.pop_back();
            q.push_back({nums[i], i});
        }
        ans.push_back(q.front().first);
        for(int i = k; i<n; ++i){
            while(!q.empty() && q.back().first < nums[i]) q.pop_back();
            while(!q.empty() && q.front().second < (i-k+1)) q.pop_front();
            q.push_back({nums[i], i});
            ans.push_back(q.front().first);
        }

        return ans;
        
        // {3,1}
        // {3, 1} {-3, 3}
        // {5, 4}
        // {5,4} {3, 5}
        // {6,6}{5,4}{3,5}
        // {7,7}{6,6}{3,5}
        

    }
};