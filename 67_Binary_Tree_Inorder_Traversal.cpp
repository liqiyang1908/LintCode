class Solution {
public:
    /**
     * @param root: A Tree
     * @return: Inorder in ArrayList which contains node values.
     */
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder;
        stack<TreeNode*>stk;
        TreeNode* dummy = new TreeNode(0);
        dummy->right = root;
        stk.push(dummy);
        while (!stk.empty())
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
            if (!stk.empty())
                inorder.push_back(stk.top()->val);
        }
        return inorder;
    }
};
