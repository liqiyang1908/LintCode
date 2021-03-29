class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int>& A) {
        int n = A.size();
        vector<vector<int>>dp(n + 1, vector<int>(m + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = true;
            for (int j = 1; j <= m; j++)
            {
                if (j >= A[i - 1])
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - A[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        for (int i = m; i >= 0; i--)
        {
            if (dp[n][i])
                return i;
        }
        return -1;
    }
};