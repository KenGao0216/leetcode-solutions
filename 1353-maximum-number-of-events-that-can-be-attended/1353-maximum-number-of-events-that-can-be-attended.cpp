class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int ans = 0;
        int day = 0;
        int i = 0;
        priority_queue<int,vector<int>, greater<int>>pq;
        while(i<events.size() || !pq.empty()){
            if(pq.empty()) day = events[i][0];
            
            while(i<events.size() && events[i][0] <=day){
                pq.push(events[i][1]);
                i++;
            }

            while(!pq.empty() && pq.top() < day){
                pq.pop();
            }
            if(!pq.empty()){
                pq.pop();
                ans++;
                day++;
            }
        }
        return ans;
    }
};