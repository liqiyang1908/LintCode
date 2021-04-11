class Solution {
public:
    /**
     * @param root: The root of binary tree
     * @return: root of new tree
     */
    TreeNode* cloneTree(TreeNode* root) {
        if (!root)
            return nullptr;
        TreeNode* newnode = new TreeNode(root->val);
        newnode->left = cloneTree(root->left);
        newnode->right = cloneTree(root->right);
        return newnode;
    }
};