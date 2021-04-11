class Solution {
public:
    /**
     * @param a: the root of binary tree a.
     * @param b: the root of binary tree b.
     * @return: true if they are identical, or false.
     */
    bool helper(TreeNode* a, TreeNode* b)
    {
        if (!a && !b)
            return true;
        if (!a || !b)
            return false;
        return a->val == b->val && helper(a->left, b->left) && helper(a->right, b->right);
    }
    bool isIdentical(TreeNode* a, TreeNode* b) {
        return helper(a, b);
    }
};