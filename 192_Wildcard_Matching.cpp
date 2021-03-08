class Solution {
public:
    /**
     * @param s: A string
     * @param p: A string includes "?" and "*"
     * @return: is Match?
     */
    bool allstar(string& p, int pindex)
    {
        for (int i = pindex; i < p.size(); i++)
        {
            if (p[i] != '*')
                return false;
        }
        return true;
    }
    bool ischarmatch(string& s, string& p, int sindex, int pindex)
    {
        if (s[sindex] == p[pindex])
            return true;
        else
            return p[pindex] == '?';
    }
    bool helper(string& s, string& p, int sindex, int pindex, vector<vector<bool>>& visited, vector<vector<bool>>& matched)
    {
        if (p.size() == pindex)
            return sindex == s.size();
        if (sindex == s.size())
        {
            return allstar(p, pindex);
        }
        if (visited[sindex][pindex])
            return matched[sindex][pindex];
        bool match;
        if (p[pindex] != '*')
            match = ischarmatch(s, p, sindex, pindex) && helper(s, p, sindex + 1, pindex + 1, visited, matched);
        else
            match = helper(s, p, sindex, pindex + 1, visited, matched) || helper(s, p, sindex + 1, pindex, visited, matched);
        visited[sindex][pindex] = true;
        matched[sindex][pindex] = match;
        return match;
    }
    bool isMatch(string& s, string& p) {
        vector<vector<bool>>visited(s.size(), vector<bool>(p.size(), false));
        vector<vector<bool>>matched(s.size(), vector<bool>(p.size(), false));
        return helper(s, p, 0, 0, visited, matched);
    }
};