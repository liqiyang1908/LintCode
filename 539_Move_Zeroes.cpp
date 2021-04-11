class Solution {
public:
    /**
     * @param nums: an integer array
     * @return: nothing
     */
    void moveZeroes(vector<int>& nums) {
        if (nums.size() < 2)
            return;
        int i = 0, j = 0;
        while (j < nums.size())
        {
            if (nums[j] != 0)
                swap(nums[i++], nums[j]);
            j++;
        }
    }
};


//Method 2
class Solution {
public:
    /**
     * @param nums: an integer array
     * @return: nothing
     */
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            if (nums[right] != 0)
            {
                nums[left++] = nums[right];
            }
        }
        while (left < nums.size())
            nums[left++] = 0;
    }
};
