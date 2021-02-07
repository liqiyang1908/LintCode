 
class Solution {
public:
    /**
     * @param nums: an integer array
     * @param target: An integer
     * @return: the difference between the sum and the target
     */
    int twoSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 2)
            return 0;
        int l = 0, r = nums.size() - 1, sum = 0, mindiff = INT_MAX;
        sort(nums.begin(), nums.end());
        while (l < r)
        {
            sum = nums[l] + nums[r];
            if (sum <= target)
            {
                l++;
            }
            else
                r--;
            mindiff = min(abs(sum - target), mindiff);
        }
        return mindiff;
    }
};