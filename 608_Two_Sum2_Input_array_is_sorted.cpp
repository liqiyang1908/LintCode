class Solution {
public:
    /**
     * @param nums: an array of Integer
     * @param target: target = nums[index1] + nums[index2]
     * @return: [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>res;
        if (nums.size() < 2)
            return res;
        int i = 0, j = nums.size() - 1;
        while (i < j)
        {
            if (nums[i] + nums[j] == target)
                return { i + 1, j + 1 };
            else if (nums[i] + nums[j] < target)
                i++;
            else
                j--;
        }
        return res;
    }
};