class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int,int> m;
        for (auto& t : transactions) {
            m[t[0]] -= t[2];
            m[t[1]] += t[2];
        }
        vector<int> bal;
        for (auto& [id, b] : m)
            if (b != 0) bal.push_back(b);
        return dfs(bal, 0);
    }

    int dfs(vector<int>& bal, int i) {
        int n = bal.size();
        while (i < n && bal[i] == 0) i++;
        if (i == n) return 0;

        int best = INT_MAX;
        for (int j = i + 1; j < n; ++j) {
            if (bal[i] * bal[j] < 0) {          // opposite signs
                bal[j] += bal[i];
                best = min(best, 1 + dfs(bal, i + 1));
                bal[j] -= bal[i];               // undo
                if (bal[j] + bal[i] == 0) break; // perfect cancel, can't do better
            }
        }
        return best;
    }
};