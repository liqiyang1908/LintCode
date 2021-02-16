class Solution {
public:
    /*
     * @param start: a string
     * @param end: a string
     * @param dict: a set of string
     * @return: An integer
     */
    int ladderLength(string& start, string& end, unordered_set<string>& dict) {
        int n = start.size();
        queue<string>myQ;
        int length = 2;
        if (start == end)
            return 1;
        myQ.push(start);
        dict.erase(start);
        while (!myQ.empty())
        {
            int size = myQ.size();
            for (int i = 0; i < size; i++)
            {
                auto cur_word = myQ.front();
                myQ.pop();
                for (int j = 0; j < start.size(); j++)
                {
                    char old_char = cur_word[j];
                    for (char new_char = 'a'; new_char <= 'z'; new_char++)
                    {
                        if (new_char == old_char)
                            continue;
                        cur_word[j] = new_char;
                        if (cur_word == end)
                            return length;
                        if (dict.find(cur_word) != dict.end())
                        {
                            myQ.push(cur_word);
                            dict.erase(cur_word);
                        }
                        cur_word[j] = old_char;
                    }
                }
            }
            length++;
        }
        return 0;
    }
};