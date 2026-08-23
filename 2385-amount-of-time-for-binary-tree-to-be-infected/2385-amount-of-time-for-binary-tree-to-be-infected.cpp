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
    unordered_map<int, vector<TreeNode*>>m;
    unordered_map<int, bool>vis;
    int amountOfTime(TreeNode* root, int start) {
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
                if(!vis[nxt->val]) q.push({nxt->val, cur.second+1});
            }
        }
        
        return ans;
    }

    void dfs(TreeNode * root, TreeNode * par){
            if(!root) return;
            vis[root->val] = false;
            if(par) m[root->val].push_back(par);
            if(root->left) m[root->val].push_back(root->left);
            if(root->right) m[root->val].push_back(root->right);
            dfs(root->left, root);
            dfs(root->right, root);
    }
};