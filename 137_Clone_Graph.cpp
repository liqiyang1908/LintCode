class Solution {
public:
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    void connectneighbor(vector<UndirectedGraphNode*> nodes, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mapping)
    {
        for (auto node : nodes)
        {
            for (auto neighbor : node->neighbors)
            {
                mapping[node]->neighbors.push_back(mapping[neighbor]);
            }
        }
    }
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>clonenodes(vector<UndirectedGraphNode*>nodes)
    {
        unordered_map< UndirectedGraphNode*, UndirectedGraphNode*>mymap;
        for (auto node : nodes)
        {
            auto new_node = new UndirectedGraphNode(node->label);
            mymap[node] = new_node;
        }
        return mymap;
    }
    vector<UndirectedGraphNode*>getnodes(UndirectedGraphNode* root)
    {
        queue<UndirectedGraphNode*>myQ;
        vector<UndirectedGraphNode*>nodes;
        unordered_set<UndirectedGraphNode*>myset;
        myQ.push(root);
        myset.insert(root);
        nodes.push_back(root);
        while (!myQ.empty())
        {
            UndirectedGraphNode* cur = myQ.front();
            myQ.pop();
            for (auto neighbor : cur->neighbors)
            {
                if (myset.find(neighbor) != myset.end())
                    continue;
                myQ.push(neighbor);
                myset.insert(neighbor);
                nodes.push_back(neighbor);
            }
        }
        return nodes;
    }
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
        if (node == nullptr) {
            return node;
        }

        vector<UndirectedGraphNode*> nodes = getnodes(node);
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mapping = clonenodes(nodes);
        connectneighbor(nodes, mapping);

        return mapping[node];
    }
};