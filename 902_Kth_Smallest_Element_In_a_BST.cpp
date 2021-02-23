class Solution {
public:
    /**
     * @param root: A Tree
     * @return: Inorder in ArrayList which contains node values.
     */
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*>stk;
        TreeNode* dummy = new TreeNode(0);
        dummy->right = root;
        stk.push(dummy);
        for(int i = 0; i< k; i++)
        {
            auto node = stk.top();
            stk.pop();
            if (node->right)
            {
                node = node->right;
                while (node)
                {
                    stk.push(node);
                    node = node->left;
                }
            }
            if (stk.empty())
                break;
        }
        return stk.top()->val;
    }
};