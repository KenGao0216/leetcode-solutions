class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        int ans = INT_MAX;
        while(l<=r){
            int m = (l+r)/2;
            int x = f(m, weights);
            cout<<m<<" "<<x<<endl;
            if(x <= days){
                ans = min(ans, m);
                r = m-1;
            }
            else l = m+1;
        }
        return ans;
    }

    int f(int cap, vector<int>& weights){
        int ans = 1;
        int cur = 0;
        for(int i = 0; i<weights.size(); ++i){
            if(cur + weights[i] <= cap) cur+=weights[i];
            else {
                cur = weights[i];
                ans++;
            }
        }
        
        return ans;
    }
};