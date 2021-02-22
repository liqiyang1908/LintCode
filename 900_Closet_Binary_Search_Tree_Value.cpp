class Solution {
public:
    /**
     * @param root: the given BST
     * @param target: the given target
     * @return: the value in the BST that is closest to the target
     */
    int closestValue(TreeNode* root, double target) {
        int closetvalue = root->val;
        while (root)
        {
            if (abs(root->val - target) <= abs(closetvalue - target))
                closetvalue = root->val;
            if (root->val < target)
                root = root->right;
            else
                root = root->left;
        }
        return closetvalue;
    }
};