class Solution {
public:
    /*
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        if (root == nullptr)
            return new TreeNode(node->val);
        else if (root->val < node->val)
            root->right = insertNode(root->right, node);
        else
            root->left = insertNode(root->left, node);
        return root;
    }
};