class Solution {
public:
    /**
     * @param str: A string
     * @return: all permutations
     */
    void dfs(string& str, string& permute, vector<bool>& visited, vector<string>& res)
    {
        if (permute.size() == str.size())
            res.push_back(permute);
        for (int i = 0; i < str.size(); i++)
        {
            if (visited[i])
                continue;
            if (i > 0 && str[i] == str[i - 1] && !visited[i - 1])
                continue;
            permute.push_back(str[i]);
            visited[i] = true;
            dfs(str, permute, visited, res);
            permute.pop_back();
            visited[i] = false;
        }
    }
    vector<string> stringPermutation2(string& str) {
        string permute;
        vector<string>res;
        vector<bool>visited(str.size(), false);
        sort(str.begin(), str.end());
        dfs(str, permute, visited, res);
        return res;
    }
};