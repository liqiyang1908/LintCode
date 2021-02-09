class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target to find.
     * @return: The first position of target. Position starts from 0.
     */
    int binarySearch(vector<int>& nums, int target) {
        if (nums.size() < 1)
            return -1;
        int l = 0, r = nums.size() - 1;
        while (l + 1 < r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] >= target)
                r = mid;
            else
                l = mid;
        }
        if (nums[r] == target)
            return r;
        if (nums[l] == target)
            return l;
        return -1;
    }
};