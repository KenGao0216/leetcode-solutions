class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>g(numCourses);
        vector<int>in(numCourses, 0);
        for(auto &x: prerequisites){
            g[x[1]].push_back(x[0]);
            in[x[0]]++;
        }
        queue<int> q;
        vector<int>ans;
        for(int i = 0; i<numCourses; ++i){
            if(in[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            ans.push_back(cur);
            for(int &nxt: g[cur]){
                in[nxt]--;
                if(in[nxt] == 0) q.push(nxt);
            }
        }
        return ans.size() == numCourses ? ans : vector<int>();

    }
};