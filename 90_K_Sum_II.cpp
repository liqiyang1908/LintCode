class Solution {
public:
    /**
     * @param A: an integer array
     * @param k: a postive integer <= length(A)
     * @param targer: an integer
     * @return: A list of lists of integer
     */
    void dfs(vector<int>& A, int k, int startidx,  int target, int sum, vector<int>& path, vector<vector<int>>& res)
    {
        if (k == path.size() && sum == target)
            res.push_back(path);
        if (path.size() > k || sum > target)
            return;
        for (int i = startidx; i < A.size(); i++)
        {
            path.push_back(A[i]);
            dfs(A, k, i + 1, target, sum + A[i], path, res);
            path.pop_back();
        }
    }
    vector<vector<int>> kSumII(vector<int>& A, int k, int targer) {
        vector<int>path;
        vector<vector<int>>res;
        sort(A.begin(), A.end());
        dfs(A, k, 0, targer, 0, path, res);
        return res;
    }
};
