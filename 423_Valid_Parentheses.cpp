class Solution {
public:
    /**
     * @param s: A string
     * @return: whether the string is a valid parentheses
     */
    bool isValidParentheses(string& s) {
        stack<char>stk;
        for (auto c : s)
        {
            if (c == '{' || c == '[' || c == '(')
                stk.push(c);
            else if (c == ')')
            {
                if (stk.empty() || stk.top() != '(')
                    return false;
                stk.pop();
            }
            else if (c == ']')
            {
                if (stk.empty() || stk.top() != '[')
                    return false;
                stk.pop();
            }
            else if (c == '}')
            {
                if (stk.empty() || stk.top() != '{')
                    return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};