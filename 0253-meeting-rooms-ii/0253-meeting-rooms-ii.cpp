class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size(); 
        if(n==1) return 1;
        sort(intervals.begin(), intervals.end(), [](const vector<int>&a, const vector<int>&b){
            return a[0] < b[0];
        });
        priority_queue<int, vector<int>, greater<int>>pq;
        for(auto &v: intervals){
            if(!pq.empty() && pq.top() <= v[0]) pq.pop();
            pq.push(v[1]);
        }
        return pq.size();
    }
};