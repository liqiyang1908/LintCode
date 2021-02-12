/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
public:
    /**
     * @param grid: a chessboard included 0 (false) and 1 (true)
     * @param source: a point
     * @param destination: a point
     * @return: the shortest path
     */
    bool isvalid(vector<vector<bool>>& grid, int x, int y)
    {
        if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 0)
            return true;
        return false;
    }
    int shortestPath(vector<vector<bool>>& grid, Point& source, Point& destination) {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int distance = -1;

        int dx[] = {1,1,-1,-1,2,2,-2,-2};
        int dy[] = {2,-2,2,-2,1,-1,1,-1};
        queue<Point>myq;
        myq.push(source);
        grid[source.x][source.y] = 1;
        while (!myq.empty())
        {
            int size = myq.size();
            distance++;
            for (int i = 0; i < size; i++)
            {
                Point curcor = myq.front();
                myq.pop();
                
                if (curcor.x == destination.x && curcor.y == destination.y)
                    return distance;
                for (int j = 0; j < 8; j++)
                {
                    int nextx = curcor.x + dx[j];
                    int nexty = curcor.y + dy[j];
                    if (isvalid(grid, nextx, nexty))
                    {
                        grid[nextx][nexty] = 1;
                        myq.emplace(nextx, nexty);
                    }
                }
            }
        }
        return -1;
    }
};