//method 1
class Solution {
public:
    /*
     * @param root: the root of binary tree
     * @param target: An integer
     * @return: all valid paths
     */
    void dfs(TreeNode* root, int target, vector<int>& path, vector<vector<int>>& res, int sum)
    {
        if (!root->left && !root->right)
        {
            if (sum == target)
                res.push_back(path);
            return;
        }
        if (root->left)
        {
            path.push_back(root->left->val);
            dfs(root->left, target, path, res, sum + root->left->val);
            path.pop_back();
        }
        if (root->right)
        {
            path.push_back(root->right->val);
            dfs(root->right, target, path, res, sum + root->right->val);
            path.pop_back();
        }
    }
    vector<vector<int>> binaryTreePathSum(TreeNode* root, int target) {
        vector<vector<int>>res;
        vector<int>path;
        if (!root)
            return res;
        path.push_back(root->val);
        dfs(root, target, path, res, root->val);
        return res;
    }
};





//method 2
class Solution {
public:
    /*
     * @param root: the root of binary tree
     * @param target: An integer
     * @return: all valid paths
     */
    void dfsTreePathSum(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& results)
    {
        if (!root)
            return;
        path.push_back(root->val);
        if (!root->left && !root->right && root->val == sum)
        {

            results.push_back(path);
        }
        dfsTreePathSum(root->left, sum - root->val, path, results);
        dfsTreePathSum(root->right, sum - root->val, path, results);
        path.pop_back();
    }
    vector<vector<int>> binaryTreePathSum(TreeNode* root, int target) {
        vector<vector<int>>result;
        if (!root)
            return result;
        vector<int>path;
        dfsTreePathSum(root, target, path, result);
        return result;
    }
};