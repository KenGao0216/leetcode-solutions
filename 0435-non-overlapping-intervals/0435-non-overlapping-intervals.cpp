class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 1) return 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int>&a, const vector<int>&b) {
                if(a[1] < b[1]) return a[1] < b[1];
                else if(a[1] == b[1]) return a[0] < b[0];
                else return b[1] > a[1];
        });
        // for(auto &i: intervals){
        //     cout<<"["<<i[0]<<","<<i[1]<<"], ";
        // }
        int n = intervals.size();
        int e = intervals[0][1];
        int ans = 0;
        for(int i = 1; i<n; ++i){
            if(intervals[i][0] >=e) e = intervals[i][1];
            else {
                ans++;
                e = min(e, intervals[i][1]);
            }
        }
        return ans;


    }
};