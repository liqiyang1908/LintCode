class Solution {
public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    static bool cmp(const Interval& a, const Interval& b)
    {
        return a.start < b.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval>res;
        if (intervals.size() < 1)
            return res;
        sort(intervals.begin(), intervals.end(), cmp);
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i].start <= res.back().end)
                res.back().end = max(res.back().end, intervals[i].end);
            else
                res.push_back(intervals[i]);
        }
        return res;
    }
};