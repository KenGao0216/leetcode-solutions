class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>>g;
        unordered_map<char, int>in;
        for (auto& word : words) {
            for (char c : word) {
                in[c] = 0;
            }
        }

        for(int i = 0; i<words.size()-1; ++i){
            int id = 0;
            while(id < min(words[i].size(), words[i+1].size()) && words[i][id] == words[i+1][id]) id++;
            cout<<"id: "<<id<<"\n";
            if (id == min(words[i].size(), words[i+1].size())) {
                if (words[i].size() > words[i+1].size()) return "";
                continue;
            }
            if (!g[words[i][id]].count(words[i+1][id])) {
                g[words[i][id]].insert(words[i+1][id]);
                in[words[i+1][id]]++;
            }
        }
        queue<char>q;
        string ans = "";
        for(auto [x,y]:in) {
            if(y==0){
                q.push(x);
            }
        }
        while(!q.empty()){
            char c = q.front();
            ans+=c;
            q.pop();
            for(char nxt:g[c]){
                in[nxt]--;
                if(in[nxt]==0) q.push(nxt);
            }
        }
        return ans.size() == in.size()? ans : "";
    }
};

