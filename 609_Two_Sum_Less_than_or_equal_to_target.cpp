class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: an integer
     * @return: an integer
     */
    int twoSum5(vector<int>& nums, int target) {
        if (nums.size() < 2)
            return 0;
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1, count = 0, sum;
        while (l < r)
        {
            sum = nums[l] + nums[r];
            if (sum <= target)
            {
                count+=r-l;
                l++;
            }
            else
                r--;
        }
        return count;
    }
};