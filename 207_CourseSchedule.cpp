#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegerees(numCourses, 0);
        queue<int> zeros;
        int count = 0;
        
        //build graph
        for(auto edge : prerequisites)
        {
            graph[edge.first].push_back(edge.second);
            indegerees[edge.second] ++;
        }
        
        //find zero indegeree node
        for(int i = 0; i < numCourses; i++)
        {
            if(indegerees[i] == 0)
                zeros.push(i);
        }
        
        while(!zeros.empty())
        {
            int cur = zeros.front();
            zeros.pop();
            count ++;
            
            for(int edge : graph[cur])
            {
                indegerees[edge] --;
                if(indegerees[edge] == 0)
                {
                    zeros.push(edge);
                }
            }
        }
        return count == numCourses;
    }
};