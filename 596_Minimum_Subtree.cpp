class Solution {
public:
    /**
     * @param root: the root of binary tree
     * @return: the root of the minimum subtree
     */
    int minval = INT_MAX;
    TreeNode* minnode = nullptr;
    
    int helper(TreeNode* root)
    {
        if (!root)
            return 0;
        int sum = helper(root->left) + helper(root->right) + root->val;
        if (sum < minval)
        {
            minnode = root;
            minval = sum;
        }
        return sum;
    }

    TreeNode* findSubtree(TreeNode* root) {
        helper(root);
        return minnode;
    }
};
