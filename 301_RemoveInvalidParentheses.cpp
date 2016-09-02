#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:

    bool is_valid(string s)
    {
        int count = 0;
        for(auto c : s)
        {
            if(c == '(')
                count ++;
            if(c == ')' && count -- == 0)
                return false;
        }
        return count == 0;
    }


    //BFS
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        queue<string> queue;
        unordered_set<string> visited;
        bool found = false;
        
        queue.push(s);
        visited.insert(s);
        
        while(!queue.empty())
        {
            string str = queue.front();
            queue.pop();
            
            if(is_valid(str))
            {
                res.push_back(str);
                found = true;
            }
            if(found)
                continue;
                
            for(int i = 0; i < str.size(); i++)
            {
                if(str[i] != '(' && str[i] != ')')
                    continue;
                string remove = str.substr(0, i) + str.substr(i + 1);
                if(visited.find(remove) == visited.end())
                {
                    queue.push(remove);
                    visited.insert(remove);
                }
            }
        }
        return res;
    }
};