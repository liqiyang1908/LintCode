class Solution {
public:
    /**
     * @param nums: a list of integers.
     * @param k: length of window.
     * @return: the sum of the element inside the window at each moving.
     */
    vector<int> winSum(vector<int>& nums, int k) {
        vector<int>res;
        if (nums.size() < k)
            return res;
        int i, j = 0, window_sum = 0;
        for (i = 0; i < nums.size(); i++)
        {
            while (j < nums.size() && j - i < k)
            {
                window_sum += nums[j];
                j++;
            }
            if (j - i == k)
            {
                res.push_back(window_sum);
                window_sum -= nums[i];
            }
        }
        return res;
    }
};