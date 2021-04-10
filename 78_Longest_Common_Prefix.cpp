class Solution {
public:
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() < 1)
            return "";
        string pattern = strs[0];
        for (int i = 0; i < pattern.size(); i++)
        {
            for (int j = 1; j < strs.size(); j++)
            {
                if (pattern[i] != strs[j][i])
                    return pattern.substr(0, i);
            }
        }
        return pattern;
    }
};