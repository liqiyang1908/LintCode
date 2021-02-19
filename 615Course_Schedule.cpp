class Solution {
public:
    /*
     * @param numCourses: a total of n courses
     * @param prerequisites: a list of prerequisite pairs
     * @return: true if can finish all courses or false
     */
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>>edges(numCourses, vector<int>());
        vector<int>degrees(numCourses, 0);
        queue<int>myQ;
        int courses_count = 0;
        for (auto iter : prerequisites)
        {
            degrees[iter.first]++;
            edges[iter.second].push_back(iter.first);
        }
        for (int i = 0; i < degrees.size(); i++)
        {
            if (degrees[i] == 0)
                myQ.push(i);
        }
        while (!myQ.empty())
        {
            int pre = myQ.front();
            myQ.pop();
            courses_count++;
            for (auto nextcourse : edges[pre])
            {
                degrees[nextcourse]--;
                if (degrees[nextcourse] == 0)
                    myQ.push(nextcourse);
            }
        }
        return courses_count == numCourses;
    }
};