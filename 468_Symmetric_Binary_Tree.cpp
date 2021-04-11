class Solution {
public:
    /**
     * @param root: the root of binary tree.
     * @return: true if it is a mirror of itself, or false.
     */
    bool helper(TreeNode* l, TreeNode* r)
    {
        if (!l && !r)
            return true;
        if (!l || !r)
            return false;
        return (l->val == r->val) && helper(l->left, r->right) && helper(l->right, r->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return helper(root->left, root->right);
    }
};