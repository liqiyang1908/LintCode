class Solution {
public:
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    void dfs(vector<int>& nums, int startidx, vector<int>& path, vector<vector<int>>&res)
    {
        res.push_back(path);
        for (int i = startidx; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            dfs(nums, i + 1, path, res);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>path;
        
        sort(nums.begin(), nums.end());
        dfs(nums, 0, path, res);
        return res;
    }
};