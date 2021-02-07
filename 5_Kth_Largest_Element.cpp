class Solution {
public:
    /**
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int quickselect(vector<int>& nums, int start, int end, int k)
    {
        if (start >= end)
            return nums[start];
        int l = start, r = end, pivot = nums[(start + end) / 2];
        while (l <= r)
        {
            while (l <= r && nums[l] > pivot)
                l++;
            while (l <= r && nums[r] < pivot)
                r--;
            if (l <= r)
                swap(nums[l++], nums[r--]);
        }
        if (start + k - 1 <= r)
            return quickselect(nums, start, r, k);
        else if (start + k - 1 >= l)
            return quickselect(nums, l, end, k - (l - start));
        return nums[r + 1];
    }
    int kthLargestElement(int n, vector<int>& nums) {
        if (nums.size() < n)
            return 0;
        return quickselect(nums, 0, nums.size() - 1, n);
    }
};