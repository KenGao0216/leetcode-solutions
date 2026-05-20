class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>freq;
        for(int &i:nums) freq[i]++;
        priority_queue<pair<int,int>>pq;
        for(auto &[x,y]:freq){
            pq.push({y,x});
        }
        vector<int>ans;
        for(int i = 0; i<k; ++i) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};