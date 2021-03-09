class Solution {
public:
    /**
     * @param nums: an array of Integer
     * @param target: an integer
     * @return: [num1, num2] (num1 < num2)
     */
    vector<int> twoSum7(vector<int>& nums, int target) {
        vector<int>res;
        if (nums.size() < 2)
            return res;
        unordered_set<int>mymap;
        if (target < 0)
            target = 0 - target;
        for (auto num: nums)
        {
            int first_num = num - target;
            if (mymap.find(first_num) != mymap.end())
            {
                res.push_back(first_num);
                res.push_back(num);
                return res;
            }
            if (mymap.find(num) == mymap.end())
                mymap.insert(num);
        }
        return res;
    }
};


//同向双指针
class Solution {
public:
    /**
     * @param nums: an array of Integer
     * @param target: an integer
     * @return: [num1, num2] (num1 < num2)
     */
    vector<int> twoSum7(vector<int>& nums, int target) {
        vector<int>res;
        if (nums.size() < 2)
            return res;
        int i, j = 1;
        if (target < 0)
            target = 0 - target;
        for (i = 0; i < nums.size(); i++)
        {
            j = max(i + 1, j);
            while (j < nums.size() && nums[j] - nums[i] < target)
                j++;
            if (j >= nums.size())
                break;
            if (nums[j] - nums[i] == target)
            {
                res.push_back(nums[i]);
                res.push_back(nums[j]);
                return res;
            }
        }
        return res;
    }
};
