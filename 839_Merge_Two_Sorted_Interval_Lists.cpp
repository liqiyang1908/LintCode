class Solution {
public:
    /**
     * @param list1: one of the given list
     * @param list2: another list
     * @return: the new sorted list of interval
     */
    void pushback(vector<Interval>& res, Interval& cur)
    {
        if (res.empty())
        {
            res.push_back(cur);
            return;
        }
        auto tail = res.end() - 1;
        if (tail->end < cur.start)
        {
            res.push_back(cur);
            return;
        }
        tail->end = max(tail->end, cur.end);
    }
    vector<Interval> mergeTwoInterval(vector<Interval>& list1, vector<Interval>& list2) {
        int i = 0, j = 0;
        vector<Interval>res;
        while (i < list1.size() && j < list2.size())
        {
            if (list1[i].start < list2[j].start)
                pushback(res, list1[i++]);
            else
                pushback(res, list2[j++]);
        }
        while (i < list1.size())
            pushback(res, list1[i++]);
        while (j < list2.size())
            pushback(res, list2[j++]);
        return res;
    }
};