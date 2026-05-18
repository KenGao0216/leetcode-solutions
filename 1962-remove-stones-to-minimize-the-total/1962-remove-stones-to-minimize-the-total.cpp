class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        int ans = 0;
        for(int i = 0; i<piles.size(); ++i) pq.push(piles[i]);
        for(int i = 0; i<k; ++i){
            int x = pq.top();
            pq.pop();
            pq.push(x-x/2);
        }
        while(!pq.empty()) {
            ans+=pq.top();
            pq.pop();
        }
        return ans;

    }
};