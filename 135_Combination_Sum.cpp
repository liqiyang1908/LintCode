//  method 1
class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target: An integer
     * @return: A list of lists of integers
     */
    void dfs(vector<int>& candidates, int startidx, int target, vector<int>& path, int sum, vector<vector<int>>& res)
    {
        if (sum == target)
            res.push_back(path);
        if (sum > target)
            return;
        for (int i = startidx; i < candidates.size(); i++)
        {
            if(i>0 && candidates[i] == candidates[i-1] && i>startidx)
                continue;
            path.push_back(candidates[i]);
            dfs(candidates, i, target, path, sum + candidates[i], res);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>path;
        vector<vector<int>>res;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target, path, 0, res);
        return res;
    }
};

//method 2
class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target: An integer
     * @return: A list of lists of integers
     */
    void dfs(vector<int>& candidates, int startidx, int target, int sum, vector<int>& path, vector<vector<int>>& res)
    {
        if (sum == target)
            res.push_back(path);
        if (sum > target)
            return;
        for (int i = startidx; i < candidates.size(); i++)
        {
            path.push_back(candidates[i]);
            dfs(candidates, i, target, sum + candidates[i], path, res);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        unordered_set<int>dup;
        vector<int>nums;
        for (auto it : candidates)
        {
            if (dup.find(it) == dup.end())
            {
                nums.push_back(it);
                dup.insert(it);
            }
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>>res;
        vector<int>path;
        dfs(nums, 0, target, 0, path, res);
        return res;
    }
};
