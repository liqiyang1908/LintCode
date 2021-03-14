class Solution {
public:
    /**
     * @param root: The root of binary tree
     * @return: An integer
     */
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode*>myQ;
        myQ.push(root);
        int depth = 0;
        while (!myQ.empty())
        {
            int size = myQ.size();
            depth++;
            for (int i = 0; i < size; i++)
            {
                auto cur = myQ.front();
                myQ.pop();
                if (!cur->left && !cur->right)
                    return depth;
                if (cur->left)
                    myQ.push(cur->left);
                if (cur->right)
                    myQ.push(cur->right);
            }
        }
        return depth;
    }
};