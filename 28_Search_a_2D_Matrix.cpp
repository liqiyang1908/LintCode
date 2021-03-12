class Solution {
public:
    /**
     * @param matrix: matrix, a list of lists of integers
     * @param target: An integer
     * @return: a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int m = matrix.size(), n = matrix[0].size();
        int start = 0, end = m * n - 1;
        while (start + 1 < end)
        {
            int mid = (start + end) / 2;
            int row = mid / n, col = mid % n;
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target)
                start=mid;
            else
                end=mid;
        }
        if (matrix[start / n][start % n] == target)
            return true;
        if (matrix[end / n][end % n] == target)
            return true;
        return false;

    }
};