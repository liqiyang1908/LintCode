class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: An integer
     * @return: An integer
     */
    int twoSum6(vector<int>& nums, int target) {
        if (nums.size() < 2)
            return 0;
        int i = 0, j = nums.size() - 1, count = 0;
        sort(nums.begin(), nums.end());
        while (i < j)
        {
            int sum = nums[i] + nums[j];
            if (sum == target)
            {
                count++;
                i++, j--;
                while (i < j && nums[i] == nums[i - 1])
                    i++;
                while (i < j && nums[j] == nums[j + 1])
                    j--;
            }
            else if (sum < target)
                i++;
            else
                j--;
        }
        return count;
    }
};