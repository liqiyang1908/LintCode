class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int index, string& word, int row, int col)
    {
        if (index == word.size())
            return true;
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || visited[row][col])
            return false;
        if (board[row][col] != word[index])
            return false;
        visited[row][col] = true;
        bool exist = dfs(board, visited, index + 1, word, row + 1, col) || dfs(board, visited, index + 1, word, row - 1, col)
            || dfs(board, visited, index + 1, word, row, col-1) || dfs(board, visited, index + 1, word, row, col + 1);
        visited[row][col] = false;
        return exist;
    }
    bool exist(vector<vector<char>>& board, string& word) {
        if (board.size() == 0 || board[0].size() == 0)
            return false;
        int row = board.size(), col = board[0].size();
        vector<vector<bool>>visited(row, vector<bool>(col, false));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (dfs(board, visited, 0, word, i, j))
                    return true;
            }
        }
        return false;
    }
};