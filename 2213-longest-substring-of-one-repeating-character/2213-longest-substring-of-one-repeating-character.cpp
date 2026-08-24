class Solution {
public:
    struct Node {
        int pref, suf, best;   
        char lc, rc;          
        int len;               
    };

    vector<Node> tree;
    string str;

    void build(int node, int lo, int hi) {
        if (lo == hi) {
            tree[node] = {1, 1, 1, str[lo], str[lo], 1};
            return;
        }
        int mid = (lo + hi) / 2;
        build(2 * node, lo, mid);
        build(2 * node + 1, mid + 1, hi);
        merge(node, lo, hi);
    }

    void merge(int node, int lo, int hi) {
        int mid = (lo + hi) / 2;
        Node &L = tree[2 * node];
        Node &R = tree[2 * node + 1];
        Node cur;

        cur.lc = L.lc;
        cur.rc = R.rc;
        cur.len = L.len + R.len;

        cur.pref = L.pref;
        if (L.pref == L.len && L.rc == R.lc) cur.pref += R.pref;

        cur.suf = R.suf;
        if (R.suf == R.len && R.lc == L.rc) cur.suf += L.suf;

        cur.best = max(L.best, R.best);
        if (L.rc == R.lc) cur.best = max(cur.best, L.suf + R.pref);

        tree[node] = cur;
    }

    void update(int node, int lo, int hi, int idx, char ch) {
        if (lo == hi) {
            str[idx] = ch;
            tree[node] = {1, 1, 1, ch, ch, 1};
            return;
        }
        int mid = (lo + hi) / 2;
        if (idx <= mid) update(2 * node, lo, mid, idx, ch);
        else update(2 * node + 1, mid + 1, hi, idx, ch);
        merge(node, lo, hi);
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        str=s;
        int n = str.size();
        tree.resize(4 * n);
        build(1, 0, n - 1);

        vector<int> res;
        res.reserve(queryIndices.size());
        for (int i = 0; i < (int)queryIndices.size(); i++) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            res.push_back(tree[1].best);
        }
        return res;
    }
};