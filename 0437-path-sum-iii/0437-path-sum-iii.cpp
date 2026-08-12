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
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        return f(root, root->val, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
    int f(TreeNode *root, long long sum, long long targetSum){
        if(!root) return 0;
        int cnt = 0;
        if(sum == targetSum) cnt++;
        
        if(root->left) cnt += f(root->left, sum+root->left->val, targetSum);
        if(root->right) cnt+= f(root->right, sum+root->right->val, targetSum);
        return cnt;
    }
};