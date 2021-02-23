class Solution {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode* root) {
        helper(root);
    }

    TreeNode* helper(TreeNode* root)
    {
        if (!root)
            return root;
        TreeNode* leftlast = helper(root->left);
        TreeNode* rightlast = helper(root->right);
        
        if (leftlast)
        {
            leftlast->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        if (rightlast)
            return rightlast;
        if (leftlast)
            return leftlast;
        return root;
    }
};