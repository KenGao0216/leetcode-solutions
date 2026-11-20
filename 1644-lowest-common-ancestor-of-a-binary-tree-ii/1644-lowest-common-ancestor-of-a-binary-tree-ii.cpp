class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Step 1: Find the lowest common ancestor of nodes p and q
        TreeNode* ans = LCA(root, p, q);

        // Step 2: Check if the LCA is p, meaning q must be in p's subtree
        if (ans == p) {
            // Verify if q is in the subtree of p
            return dfs(p, q) ? p : NULL;
        }
        // Step 3: Check if the LCA is q, meaning p must be in q's subtree
        else if (ans == q) {
            // Verify if p is in the subtree of q
            return dfs(q, p) ? q : NULL;
        }

        // Step 4: If neither p nor q is the ancestor of the other, return the
        // LCA
        return ans;
    }

    TreeNode* LCA(TreeNode* node, TreeNode* p, TreeNode* q) {
        // Base case: if the current node is null, p, or q, return the current
        // node
        if (node == NULL || node == p || node == q) return node;

        // Recursive case: find LCA in left and right subtrees
        TreeNode* left = LCA(node->left, p, q);
        TreeNode* right = LCA(node->right, p, q);

        // If p and q are found in different subtrees, current node is their LCA
        if (left && right) return node;

        // Otherwise, return the non-null result (either left or right)
        else if (left)
            return left;
        else
            return right;
    }

    bool dfs(TreeNode* node, TreeNode* target) {
        // Base case: target found
        if (node == target) return true;

        // Base case: reached null, target not found
        if (node == NULL) return false;

        // Recursive case: search target in left or right subtree
        return dfs(node->left, target) || dfs(node->right, target);
    }
};