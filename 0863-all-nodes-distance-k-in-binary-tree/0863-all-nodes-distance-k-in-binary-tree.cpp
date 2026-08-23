/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, vector<TreeNode*>>m;
    unordered_map<TreeNode*, bool>vis;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        dfs(root, nullptr);
        queue<pair<TreeNode*, int>>q;
        q.push({target, 0});
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            vis[cur.first] = true;
            if(cur.second == k) ans.push_back(cur.first->val);
            for(auto nxt: m[cur.first]){
                if(!vis[nxt]) q.push({nxt, cur.second+1});
            }
        }
        
        return ans;
    }

    void dfs(TreeNode * root, TreeNode * par){
            if(!root) return;
            vis[root] = false;
            if(par) m[root].push_back(par);
            if(root->left) m[root].push_back(root->left);
            if(root->right) m[root].push_back(root->right);
            dfs(root->left, root);
            dfs(root->right, root);
    }

    
};