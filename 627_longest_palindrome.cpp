class Solution {
public:
    /**
     * @param s: a string which consists of lowercase or uppercase letters
     * @return: the length of the longest palindromes that can be built
     */
    int longestPalindrome(string& s) {
        unordered_map<char, int>frequency;
        for (auto c : s)
            frequency[c]++;
        int even = 0, odd = 0;
        for (auto it : frequency)
        {
            if (it.second % 2 == 0)
            {
                even += it.second;
            }
            else
            {
                if (it.second > 1)
                {
                    even += it.second - 1;
                }
                odd = 1;
            }
        }
        return even + odd;
    }
};