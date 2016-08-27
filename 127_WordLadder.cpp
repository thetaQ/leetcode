#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return an integer
      */
    
    vector<string> get_neighbours(string str)
    {
        vector<string> res;
        for(int i = 0; i < str.size(); ++i)
        {
            char tmp = str[i];
            for(int c = 'a'; c <= 'z'; c++)
            {
                if(c == tmp)
                    continue;
                str[i] = c;
                res.push_back(str);
            }
            str[i] = tmp;
        }
        return res;
    }
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // write your code here
        if(start == end)
            return 1;
        queue<string> q;
        unordered_map<string, bool> visited;
        q.push(start);
        visited[start] = true;
        int count = 1;
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                string s = q.front();
                q.pop();
                vector<string> neighbours = get_neighbours(s);
                for(auto n: neighbours)
                {
                    if(n == end)
                        return count+1;
                    if(dict.find(n) != dict.end() && !visited[n])
                    {
                        visited[n] = true;
                        q.push(n);
                    }
                }
            }
            count ++;
        }
        return 0;
    }
};