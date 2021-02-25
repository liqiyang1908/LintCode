class Solution {
public:
    void dfs(vector<int>& nums, int index, vector<int>& path, vector<vector<int>>& res)
    {
        res.push_back(path);
        for (int i = index; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1] && i > index)
                continue;
            path.push_back(nums[i]);
            dfs(nums, i + 1, path, res);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>path;
        vector<vector<int>>res;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, path, res);
        return res;
    }
};