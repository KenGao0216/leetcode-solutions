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
    int ans;
    int averageOfSubtree(TreeNode* root) {
        f(root);
        return ans;
    }

    pair<int,int> f(TreeNode* root){
        if(!root) return {0,0};
        auto [lsum, lcnt] = f(root->left);
        auto [rsum, rcnt] = f(root->right);
        int sum  = lsum+rsum+root->val;
        int cnt = lcnt + rcnt + 1;
        if(sum / cnt == root->val) ans++;
        return {sum, cnt};
    }
};