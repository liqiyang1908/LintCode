class Solution {
public:
    /**
     * @param nums: an array of integers
     * @return: the number of unique integers
     */
    int deduplication(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        int j = 1, i = 0;
        sort(nums.begin(), nums.end());
        for (; i < nums.size(); i++)
        {
            while (j < nums.size() && nums[j] == nums[i])
                j++;
            if (j >= nums.size())
                break;
            nums[i + 1] = nums[j];
        }
        return i + 1;
    }
};