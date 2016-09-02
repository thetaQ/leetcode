#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool dfs(vector<int>& res, vector<vector<int>>& graph, vector<int>& visited, int cur_node)
    {
        if(visited[cur_node] == -1)
            return false;
        if(visited[cur_node] == 1)
            return true;
        
        visited[cur_node] = -1;
        for(auto edge : graph[cur_node])
        {
            if(!dfs(res, graph, visited, edge))
                return false;
        }
        res.push_back(cur_node);
        visited[cur_node] = 1;
        return true;
    }
    
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        vector<int> res;
        vector<int> visited(numCourses, 0);
        
        //build graph
        for(auto edge: prerequisites)
        {
            graph[edge.first].push_back(edge.second);
        }
        for(int i = 0; i < numCourses; i++)
        {
            if(!dfs(res, graph, visited, i))
            {
                vector<int> ret;
                return ret;
            }
        }
        return res;
    }

};