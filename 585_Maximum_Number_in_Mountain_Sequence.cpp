class Solution {
public:
    /**
     * @param nums: a mountain sequence which increase firstly and then decrease
     * @return: then mountain top
     */
    int mountainSequence(vector<int>& nums) {
        if (nums.size() < 1)
            return -1;
        int start = 0, end = nums.size() - 1;
        while (start + 1 < end)
        {
            int mid = (start + end) / 2;
            if (nums[mid] < nums[mid + 1])
                start = mid;
            else
                end = mid;
        }
        return max(nums[start], nums[end]);
    }
};