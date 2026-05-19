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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode *lca = LCA(root, startValue, destValue);
        string p1, p2, path;
        dfs(lca, startValue, path, p1); 
        dfs(lca, destValue, path, p2);
        return string(p1.length(), 'U') + p2;
        
    }
    TreeNode* LCA(TreeNode* root, int p, int q){
        if(!root) return nullptr;
        if(root->val == p || root->val == q) return root;
        TreeNode* left = LCA(root->left, p, q);
        TreeNode* right = LCA(root->right, p, q);
        if(left && right) return root;
        return left? left: right;
    }

    void dfs(TreeNode* root, int dest, string & path, string &p){
        if(!root) return;
        if(root->val == dest) {p = path; return;}
        path+="L";
        dfs(root->left, dest, path, p);
        path.pop_back();
        path+="R";
        dfs(root->right, dest, path, p);
        path.pop_back();
    }

    
};