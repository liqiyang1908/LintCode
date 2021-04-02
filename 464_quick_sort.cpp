class Solution {
public:
    void quicksort(vector<int>& A, int start, int end)
    {
        if (start >= end)
            return;
        int l = start, r = end, pivot = A[(start + end) / 2];
        while (l <= r)
        {
            while (A[l] < pivot)
                l++;
            while (A[r] > pivot)
                r--;
            if (l <= r)
                swap(A[l++], A[r--]);
        }
        quicksort(A, start, r);
        quicksort(A, l, end);
    }
    void sortIntegers2(vector<int>& A) {
        if (A.size() < 2)
            return;
        quicksort(A, 0, A.size() - 1);
    }
};