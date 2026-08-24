class Solution {
public:

    struct Node{
        int pref;
        int suf;
        int best;
        char lc;
        char rc;
        int len;
    };
    vector<Node>tree;
    string str;

    void build(int node, int lo, int hi){
        if(lo==hi) {tree[node] = {1,1,1,str[lo], str[hi], 1}; return;}
        int mid = (lo+hi)/2;
        build(2*node, lo, mid);
        build(2*node+1, mid+1, hi);
        merge(node, lo, hi);
    }

    void merge(int node, int lo, int hi){
        int mid = (lo+hi)/2;
        Node &L = tree[node*2];
        Node &R = tree[node*2+1];
        Node cur;
        cur.lc = L.lc;
        cur.rc = R.rc;
        cur.len = L.len+R.len;

        cur.pref = L.pref;
        if(L.pref == L.len && L.rc == R.lc) cur.pref+=R.pref;

        cur.suf = R.suf;
        if(R.suf == R.len && R.lc == L.rc) cur.suf+=L.suf;

        cur.best = max(L.best, R.best);
        if(L.rc == R.lc) cur.best = max(cur.best, L.suf+R.pref);
        tree[node] = cur;
    }

    void update(int node, int lo, int hi, int id, char c){
        if(lo==hi) {
            str[id] = c;
            tree[node] = {1,1,1, c,c,1};
            return;
        }
        int mid = (lo+hi)/2;
        if(id<=mid) update(node*2, lo, mid, id, c);
        else update(node*2+1, mid+1, hi, id, c);
        merge(node, lo, hi);
    }
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        str = s;
        vector<int>ans;
        int n = s.length();
        tree.resize(4*n);
        build(1, 0, n-1);
        for(int i = 0; i<queryCharacters.size(); ++i){
                update(1, 0, n-1, queryIndices[i], queryCharacters[i]);
                ans.push_back(tree[1].best);
        }
        return ans;
    }
};