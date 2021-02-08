class Solution {
public:
    /**
     * @param nums: An integer array sorted in ascending order
     * @param target: An integer
     * @return: An integer
     */
    int lastPosition(vector<int>& nums, int target) {
        if (nums.size() < 1)
            return -1;
        int l = 0, r = nums.size() - 1;
        while (l + 1 < r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] <= target)
                l = mid;
            else
                r = mid;
        }
        if (nums[r] == target)
            return r;
        if (nums[l] == target)
            return l;
        return -1;
    }
};