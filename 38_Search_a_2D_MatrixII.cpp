class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
        int row = matrix.size(), col = matrix[0].size();
        int i = row - 1, j = 0, count = 0;
        while (i >= 0 && j < col)
        {
            if (matrix[i][j] == target)
            {
                count++;
                i--;
                j++;
            }
            else if (matrix[i][j] < target)
                j++;
            else
                i--;
        }
        return count;
    }
};