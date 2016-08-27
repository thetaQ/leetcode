#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

 struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // write your code here
        if(node == NULL)
            return NULL;
        queue<UndirectedGraphNode *> queue;
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> htable;
        
        UndirectedGraphNode *cloned = new UndirectedGraphNode(node->label);
        queue.push(node);
        htable[node] = cloned;
        
        while(!queue.empty())
        {
            UndirectedGraphNode *old = queue.front();
            UndirectedGraphNode *new_node = htable[old];
            queue.pop();
            for(auto neighbor: old->neighbors)
            {
                UndirectedGraphNode *new_cloned = NULL;
                if(htable.find(neighbor) == htable.end())
                {
                    new_cloned = new UndirectedGraphNode(neighbor->label);
                    queue.push(neighbor);
                    htable[neighbor] = new_cloned;
                }
                else
                {
                    new_cloned = htable[neighbor];
                }
                new_node->neighbors.push_back(new_cloned);
            }
        }
        return cloned;
    }
};