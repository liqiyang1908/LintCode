class Solution {
public:
    /*
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    void dfs(vector<int>& nums, vector<bool>&visited, vector<int>& path, vector<vector<int>>& res)
    {
        if (path.size() == nums.size())
            res.push_back(path);
        for (int i = 0; i < nums.size(); i++)
        {
            if (visited[i])
                continue;
            if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1])
                continue;
            path.push_back(nums[i]);
            visited[i] = true;
            dfs(nums, visited, path, res);
            visited[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>path;
        vector<bool>visited(nums.size(), false);
        sort(nums.begin(), nums.end());
        dfs(nums, visited, path, res);
        return res;
    }
};