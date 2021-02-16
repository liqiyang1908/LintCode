class Solution {
public:
    /*
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
        unordered_map<DirectedGraphNode*, int>mymap;
        vector<DirectedGraphNode*>res;
        queue<DirectedGraphNode*>myQ;
        if (graph.size() < 1)
            return res;
        for (auto vertex : graph)
        {
            for (auto neighbor : vertex->neighbors)
            {
                if (mymap.find(neighbor) == mymap.end())
                    mymap[neighbor] = 1;
                else
                    mymap[neighbor]++;
            }
        }
        for (auto v : graph)
        {
            if (mymap[v] == 0)
                myQ.push(v);
        }
        while (!myQ.empty())
        {
            auto cur = myQ.front();
            myQ.pop();
            res.push_back(cur);
            for (auto neighbor : cur->neighbors)
            {
                mymap[neighbor]--;
                if (mymap[neighbor] == 0)
                    myQ.push(neighbor);
            }
        }
        return res;
    }
};