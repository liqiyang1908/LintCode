class Solution {
public:
    /**
     * @param s: A string
     * @return: Whether the string is a valid palindrome
     */
    bool isPalindrome(string& s) {
        if (s.size() < 2)
            return true;
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            if (!isalnum(s[i]))
                i++;
            else if (!isalnum(s[j]))
                j--;
            else if (tolower(s[i++]) != tolower(s[j--]))
                return false;
        }
        return true;
    }
};