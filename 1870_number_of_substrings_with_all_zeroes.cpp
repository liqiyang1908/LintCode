class Solution {
public:
    /**
     * @param str: the string
     * @return: the number of substrings
     */
    int stringCount(string& str) {
        if (str.size() < 1)
            return 0;
        int i = 0, j = i + 1, count = 0;
        for (; i < str.size(); i++)
        {
            if (str[i] != '0')
                continue;
            j = max(j, i + 1);
            while (j < str.size() && str[j] == '0')
                j++;
            count += j - i;
        }
        return count;
    }
};