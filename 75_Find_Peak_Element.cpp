class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int>& A) {
        if (A.size() < 1)
            return -1;
        int start = 1, end = A.size() - 2;
        while (start + 1 < end)
        {
            int mid = (start + end) / 2;
            if (A[mid]  < A[mid - 1])
                end = mid;
            else if (A[mid] < A[mid + 1])
                start = mid;
            else
                return mid;
        }
        if (A[start] > A[end])
            return start;
        return end;
    }
};