class Solution {
 public:
     /**
      * @param A: an integer array
      * @return: nothing
      */
     void merge(vector<int>& a, int start, int end, vector<int>& temp)
     {
         int mid = start + (end - start) / 2;
         int l = start, r = mid+1, idx = start;
         while (l <= mid && r <= end)
         {
             if (a[l] <= a[r])
                 temp[idx++] = a[l++];
             else
                 temp[idx++] = a[r++];
         }
         while (l <= mid)
             temp[idx++] = a[l++];
         while (r <= end)
             temp[idx++] = a[r++];
         for (int i = start; i <= end; i++)
             a[i] = temp[i];
     }
     void mergesort(vector<int>& a, int start, int end, vector<int>& temp)
     {
         if (start >= end)
             return;
         int mid = start + (end - start) / 2;
         mergesort(a, start, mid, temp);
         mergesort(a, mid + 1, end, temp);
         merge(a, start, end, temp);
     }
     void sortIntegers2(vector<int>& A) {
         if (A.size() < 2)
             return;
         vector<int>temp(A.size(), 0);
         mergesort(A, 0, A.size() - 1, temp);
     }
 };