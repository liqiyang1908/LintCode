
class Solution {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode* root) {
        if (!root)
            return;
        invertBinaryTree(root->left);
        invertBinaryTree(root->right);
        swap(root->left, root->right);
    }
};