class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    void dfs(vector<int>& nums, int k,int index, vector<int>& path, vector<vector<int>>& res)
    {
        if (path.size() == k)
            res.push_back(path);
        for (int i = index; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            dfs(nums, k, i + 1, path, res);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;
        vector<int>nums, path;
        for (int i = 1; i <= n; i++)
        {
            nums.push_back(i);
        }
        dfs(nums, k, 0, path, res);
        return res;
    }
};