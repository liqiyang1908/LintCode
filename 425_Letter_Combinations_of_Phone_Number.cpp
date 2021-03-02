class Solution {
public:

    /**
     * @param digits: A digital string
     * @return: all posible letter combinations
     */
    const vector<string> keyboard{ " ", "", "abc", "def", // '0','1','2',...
       "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    void dfs(string& digits, int index, string& path, vector<string>& res)
    {
        if (index == digits.size())
            res.push_back(path);
        int digi = digits[index] - '0';
        string keystr = keyboard[digi];
        for (int i = 0; i < keystr.size(); i++)
        {
            path.push_back(keystr[i]);
            dfs(digits, index + 1, path, res);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string& digits) {
        vector<string>res;
        string path;
        if (digits.size() < 1)
            return res;
        dfs(digits, 0, path, res);
        return res;
    }
};