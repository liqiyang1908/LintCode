class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @return: Find all unique triplets in the array which gives the sum of zero.
     */
    void twosum(vector<int>& num, int first, int left, int right, vector<vector<int>>& res)
    {
        int target = 0 - num[first];
        while (left < right)
        {
            if (left > first + 1 && num[left] == num[left - 1])
                left++;
            else if (num[left] + num[right] == target)
            {
                vector<int>temp = { num[first], num[left++], num[right--] };
                res.push_back(temp);
            }
            else if (num[left] + num[right] < target)
                left++;
            else
                right--;
        }
    }
    vector<vector<int>> threeSum(vector<int>& numbers) {
        vector<vector<int>>res;
        if (numbers.size() < 3)
            return res;
        sort(numbers.begin(), numbers.end());
        for (int i = 0; i < numbers.size() - 2; i++)
        {
            if (i > 0 && numbers[i] == numbers[i - 1])
                continue;
            twosum(numbers, i, i + 1, numbers.size() - 1, res);
        }
        return res;
    }
};