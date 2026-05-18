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
    vector<int>s1; vector<int>s2;
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
            dfs(root1, s1);
            dfs(root2, s2);
            return s1==s2;
    }

    void dfs(TreeNode* root, vector<int>&v){
        if(!root) return;
        if(!root->left && !root->right)  v.push_back(root->val);
        if(root->left) dfs(root->left, v);
        if(root->right) dfs(root->right, v);
    }
};