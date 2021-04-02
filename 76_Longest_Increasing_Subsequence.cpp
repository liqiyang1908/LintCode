class Solution {
public:
    /**
     * @param nums: An integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int>& nums) {
        if (nums.size() < 1)
            return 0;
        int n = nums.size();
        vector<int>dp(n, 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        int maxlen = 0;
        for (int i = 0; i < n; i++)
        {
            maxlen = max(dp[i], maxlen);
        }
        return maxlen;
    }
};