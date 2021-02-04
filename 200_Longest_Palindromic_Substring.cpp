class Solution {
public:
    /**
     * @param s: input string
     * @return: a string as the longest palindromic substring
     */
    int substrlen(string& s, int left, int right)
    {
        int len = 0, i = left, j = right;
        while (left >= 0 && right < s.size())
        {
            if (s[left] != s[right])
                break;
            len = right - left + 1;
            left--, right++;
        }
        return len;
    }
    string longestPalindrome(string& s) {
        if (s.size() < 2)
            return s;
        int start = 0, len = 0, longest = 0;
        for (int i = 0; i < s.size(); i++)
        {
            len = substrlen(s, i, i);
            if (len > longest)
            {
                start = i - len/2;
                longest = len;
            }
            len = substrlen(s, i, i + 1);
            if (len > longest)
            {
                start = i - len/2 +1;
                longest = len;
            }
        }
        return s.substr(start, longest);
    }
};