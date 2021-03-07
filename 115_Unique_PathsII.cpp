class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size(), col = obstacleGrid[0].size();
        vector<vector<int>>dp(row, vector<int>(col, 0));
        if (obstacleGrid[0][0])
            return 0;
        dp[0][0] = 1;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                if (obstacleGrid[i][j])
                {
                    dp[i][j] = 0;
                    continue;
                }
                if (i > 0)
                    dp[i][j] += dp[i - 1][j];
                if (j > 0)
                    dp[i][j] += dp[i][j - 1];
            }
        }
        return dp[row - 1][col - 1];
    }
};