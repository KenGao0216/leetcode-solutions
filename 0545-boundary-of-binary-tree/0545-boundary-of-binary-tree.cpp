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
    vector<int>ans;
    vector<int>r;
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(!root) return ans;
        ans.push_back(root->val);
        if(root->left) findLeft(root->left);
        if(root->left || root->right) findLeaves(root);
        if(root->right) findRight(root->right);
        for(int i = r.size()-1; i>=0; --i) ans.push_back(r[i]);
        return ans;
    }
    void findLeft(TreeNode* root){
        if(root->left || root->right) ans.push_back(root->val);
        if(root->left ) findLeft(root->left);
        else{
            if(root->right) findLeft(root->right);
        }
    }
    void findLeaves(TreeNode* root){
        if(!root) return; 
        if(!root->left && !root->right) {ans.push_back(root->val); return;}
        findLeaves(root->left);
        findLeaves(root->right);
    }
    void findRight(TreeNode* root){
        if(root->left || root->right) r.push_back(root->val);
        if(root->right) findRight(root->right);
        else{
            if(root->left) findRight(root->left);
        }
    }
};