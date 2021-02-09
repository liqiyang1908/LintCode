class Solution {
public:
    /**
     * @param A: an integer rotated sorted array
     * @param target: an integer to be searched
     * @return: an integer
     */
    int search(vector<int>& A, int target) {
        if (A.size() < 1)
            return -1;
        int start = 0, end = A.size() - 1;
        while (start + 1 < end)
        {
            int mid = (start + end) / 2;
            if (A[mid] == target)
            {
                return mid;
            }
            else if (A[mid] > A[start])
            {
                if (A[mid] >= target && A[start] <= target)
                    end = mid;
                else
                    start = mid;
            }
            else
            {
                if (A[mid] <= target && A[end] >= target)
                    start = mid;
                else
                    end = mid;
            }
        }
        if (A[start] == target)
            return start;
        else if (A[end] == target)
            return end;
        return -1;
    }
};