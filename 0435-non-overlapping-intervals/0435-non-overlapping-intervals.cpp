class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 1) return 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int>&a, const vector<int>&b) {
                if(a[0] < b[0]) return a[0] < b[0];
                else if(a[0] == b[0]) return a[1] < b[1];
                else return b[0] > a[0];
        });
        // for(auto &i: intervals){
        //     cout<<"["<<i[0]<<","<<i[1]<<"], ";
        // }
        int n = intervals.size();
        vector<int>ends;
        for(int i = 0; i<n; ++i){
            int j = upper_bound(ends.begin(), ends.end(), intervals[i][0]) - ends.begin();
            if(j != ends.size())  ends[j] = min(ends[j], intervals[i][1]);
            else ends.push_back(intervals[i][1]);
            
        }
        return n-ends.size();


    }
};