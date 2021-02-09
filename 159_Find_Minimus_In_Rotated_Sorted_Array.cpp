class Solution {
public:
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int>& nums) {
        if (nums.size() < 1)
            return -1;
        int l = 0, r = nums.size() - 1;
        while (l + 1 < r)
        {
            int mid = (l + r)/2;
            if (nums[mid] > nums[r])
                l = mid;
            else
                r = mid;
        }
        return min(nums[l], nums[r]);
    }
};