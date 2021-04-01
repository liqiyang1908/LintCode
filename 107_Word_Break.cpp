class Solution {
public:
    /**
     * @param s: A string
     * @param wordSet: A dictionary of words dict
     * @return: A boolean
     */
    bool wordBreak(string& s, unordered_set<string>& wordSet) {
        int n = s.size();
        vector<bool>dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (!dp[j])
                    continue;
                string word = s.substr(j, i - j);
                if (wordSet.find(word) != wordSet.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};