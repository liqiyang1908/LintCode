class Solution {
public:
    /**
     * @param A: an integer array
     * @param target: An integer
     * @param k: An integer
     * @return: an integer array
     */
    bool isleftcloser(vector<int>& A, int target, int l, int r)
    {
        if (l < 0 || l >= A.size())
            return false;
        if (r < 0 || r >= A.size())
            return true;
        return abs(A[l] - target) <= abs(A[r] - target);
    }
    int findclosetidx(vector<int>A, int target)
    {
        int l = 0, r = A.size() - 1;
        while (l + 1 < r)
        {
            int mid = (l + r) / 2;
            if (A[mid] == target)
                return mid;
            else if (A[mid] < target)
                l = mid;
            else
                r = mid;
        }
        if (abs(A[l] - target) <= abs(A[r] - target))
            return l;
        return r;
    }
    vector<int> kClosestNumbers(vector<int>& A, int target, int k) {
        vector<int>res;
        if (A.size() < 1 || A.size() < k || k == 0)
            return res;
        int closetidx = findclosetidx(A, target);
        res.push_back(A[closetidx]);
        int i = 1, l = closetidx-1, r = closetidx+1;
        while (i < k)
        {
            if (isleftcloser(A, target, l, r))
                res.push_back(A[l--]);
            else
                res.push_back(A[r++]);
            i++;
        }
        return res;
    }
};