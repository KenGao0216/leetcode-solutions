class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        unordered_map<int,long long>m;
        priority_queue<pair<long long,int>>pq;
        vector<long long>ans;
        for(int i = 0; i<(int)nums.size(); ++i){
            m[nums[i]]+=freq[i];
            pq.push({m[nums[i]], nums[i]});
            while(!pq.empty() && pq.top().first != m[pq.top().second]) pq.pop();
            ans.push_back(pq.top().first);
        }
        
        return ans;
    }
};