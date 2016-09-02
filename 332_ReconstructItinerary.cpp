#include <iostream>
#include <vector>
#include <unordered_map>
#include <priority_queue>

using namespace std;


class Solution {
public:
    void dfs(vector<string>& path, unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& graph, string from)
    {
        auto &to_queue = graph[from];
        while(!to_queue.empty())
        {
            string to = to_queue.top();
            to_queue.pop();
            dfs(path, graph, to);
        }
        path.push_back(from);
    }
    
    vector<string> findItinerary(vector<pair<string, string>> tickets)
    {
        vector<string> result;
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
        for(auto ticket: tickets)
        {
            graph[ticket.first].push(ticket.second);
        }
        dfs(result, graph, "JFK");
        reverse(result.begin(), result.end());
        return result;
    }
};