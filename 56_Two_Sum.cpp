class Solution {
public:
    /**
     * @param numbers: An array of Integer
     * @param target: target = numbers[index1] + numbers[index2]
     * @return: [index1 + 1, index2 + 1] (index1 < index2)
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int>mymap;
        for (int i = 0; i < numbers.size(); i++)
        {
            int remain = target - numbers[i];
            if (mymap.find(remain) != mymap.end())
            {
                vector<int>result = { mymap[remain], i };
                return result;
            }
            else
                mymap[numbers[i]] = i;
        }
        return {};
    }
};