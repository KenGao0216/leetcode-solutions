/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>>m;
    vector<bool>vis;
    int amountOfTime(TreeNode* root, int start) {
        m.resize(1e5+5, {});
        vis.resize(1e5+5, false);
        int ans = 0;
        dfs(root, nullptr);
        queue<pair<int, int>>q;
        q.push({start, 0});
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            vis[cur.first] = true;
            ans = max(ans, cur.second);
            for(auto nxt: m[cur.first]){
                if(!vis[nxt]) q.push({nxt, cur.second+1});
            }
        }
        
        return ans;
    }

    void dfs(TreeNode * root, TreeNode * par){
            if(!root) return;
            vis[root->val] = false;
            if(par) m[root->val].push_back(par->val);
            if(root->left) m[root->val].push_back(root->left->val);
            if(root->right) m[root->val].push_back(root->right->val);
            dfs(root->left, root);
            dfs(root->right, root);
    }
};