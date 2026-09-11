class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>&a, const vector<int>&b){
            if(a[0] == b[0]) return b[1] < a[1];
            return a[0] < b[0];
        });
        for(vector i:intervals){
            cout<<i[0]<<" "<<i[1]<<endl;
        }
        int n = intervals.size();
        int l = -2, r = -1;
        int ans = 0;
        for(vector i:intervals){
            if(i[1] <=r && i[0] >= l) continue;
            else {
                l = i[0], r = i[1];
                ans++;
            }
        }
        return ans;
    }
};