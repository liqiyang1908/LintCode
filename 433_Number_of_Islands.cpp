class coordinate {
public:
    int x;
    int y;
    coordinate(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }
};

class Solution {
public:
    /**
     * @param grid: a boolean 2D matrix
     * @return: an integer
     */
    bool isvalid(vector<vector<bool>>& grid, int x, int y)
    {
        if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size())
            return true;
        return false;
    }
    void bfsislands(vector<vector<bool>>& grid, int x, int y)
    {
        int dx[] = { 0,0,-1,1 };
        int dy[] = { 1,-1,0,0 };
        queue<coordinate>myq;
        myq.emplace(x, y);
        grid[x][y] = false;
        while (!myq.empty())
        {
            int size = myq.size();
            for (int i = 0; i < size; i++)
            {
                coordinate curcor = myq.front();
                myq.pop();
                grid[curcor.x][curcor.y] = false;
                for (int j = 0; j < 4; j++)
                {
                    int nextx = curcor.x + dx[j];
                    int nexty = curcor.y + dy[j];
                    if (isvalid(grid, nextx, nexty) && grid[nextx][nexty])
                    {
                        grid[nextx][nexty] = false;
                        myq.emplace(nextx, nexty);
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<bool>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int islands = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j])
                {
                    islands++;
                    bfsislands(grid, i, j);
                }
            }
        }
        return islands;
    }
};