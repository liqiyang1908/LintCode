class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: An integer
     * @return: an integer
     */
    int twoSum2(vector<int>& nums, int target) {
        if (nums.size() < 2)
            return 0;
        int l = 0, r = nums.size() - 1, count = 0;
        sort(nums.begin(), nums.end());
        while (l < r)
        {
            int sum = nums[l] + nums[r];
            if (sum > target)
            {
                count += r - l;
                r--;
            }
            else
                l++;
        }
        return count;
    }
};