class Solution {
public:
    /**
     * @param root: A Tree
     * @return: Level order a list of lists of integer
     */
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if (!root)
            return res;
        queue<TreeNode*>myq;
        myq.push(root);
        while (!myq.empty())
        {
            int size = myq.size();
            vector<int>level;
            for (int i = 0; i < size; i++)
            {
                TreeNode* currentnode = myq.front();
                myq.pop();
                level.push_back(currentnode->val);
                if (currentnode->left)
                    myq.push(currentnode->left);
                if (currentnode->right)
                    myq.push(currentnode->right);
            }
            res.push_back(level);
        }
        return res;
    }
};