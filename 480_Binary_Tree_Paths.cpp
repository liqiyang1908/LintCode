class Solution {
public:
    /**
     * @param root: the root of the binary tree
     * @return: all root-to-leaf paths
     */
    void dfs(TreeNode* root, string path, vector<string>& res)
    {
        if (!root->left && !root->right)
        {
            path += to_string(root->val);
            res.push_back(path);
            return;
        }
        path = path + to_string(root->val) + "->";
        if (root->left)
        {
            dfs(root->left, path, res);
        }
        if (root->right)
            dfs(root->right, path, res);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>res;
        
        if (!root)
            return res;
        string path;
        dfs(root, path, res);
        return res;
    }
};