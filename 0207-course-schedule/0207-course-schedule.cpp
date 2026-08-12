class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int cnt = 0;

        vector<int>in(numCourses, 0);
        vector<vector<int>>g(numCourses);
        for(const auto &v: prerequisites){
            g[v[1]].push_back(v[0]);
            in[v[0]]++;
        }
        queue<int>q;
        for(int i = 0; i<numCourses; ++i) if(in[i] == 0) q.push(i);
        while(!q.empty()){
            int cur = q.front();
            cnt++;
            q.pop();
            for(int nxt: g[cur]){
                in[nxt]--;
                if(in[nxt] == 0) q.push(nxt);
            }
        }

        return numCourses == cnt;
    }
};