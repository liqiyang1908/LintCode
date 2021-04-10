class Solution {
public:
    /**
     * @param source:
     * @param target:
     * @return: return the index
     */
    int strStr(string& source, string& target) {
        if (target.size() == 0)
            return 0;
        if(source.size() < target.size())
            return -1;
        for (int i = 0; i < source.size(); i++)
        {
            bool mismatch = false;
            for (int j = 0; j < target.size(); j++)
            {
                if (source[i + j] != target[j])
                {
                    mismatch = true;
                    break;
                }
            }
            if (!mismatch)
                return i;
        }
        return -1;

    }
};