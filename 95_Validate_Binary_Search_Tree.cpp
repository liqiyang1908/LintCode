class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool helper(TreeNode* root, long min_val, long max_val)
    {
        if (!root)
            return true;
        if (root->val <= min_val || root->val >= max_val)
            return false;
        return helper(root->left, min_val, root->val) && helper(root->right, root->val, max_val);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, INT64_MIN, INT64_MAX);
    }
};