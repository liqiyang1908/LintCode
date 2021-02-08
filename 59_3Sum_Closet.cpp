class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int>& numbers, int target) {
        if (numbers.size() < 3)
            return 0;
        int closet = numbers[0] + numbers[1] + numbers[2];
        sort(numbers.begin(), numbers.end());
        for (int i = 0; i < numbers.size() - 2; i++)
        {
            int l = i + 1, r = numbers.size() - 1, sum = 0;
            while (l < r)
            {
                sum = numbers[l] + numbers[r] + numbers[i];
                if (abs(sum - target) < abs(closet - target))
                    closet = sum;
                if (sum < target)
                    l++;
                else
                    r--;
            }
        }
        return closet;
    }
};