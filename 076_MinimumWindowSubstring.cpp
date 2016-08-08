#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t)
    {
        if(s.size() == 0 || t.size() == 0)
            return "";
        vector<int> map(128, 0);
        for(auto c: t)
            map[c] ++;
        int counter = t.size();
        int begin = 0, end = 0;
        int head = 0, min_res = INT_MAX;;
        while(end < s.size())
        {
            if(map[s[end++]] -- > 0)
                counter --;
            while(counter == 0)
            {
                if(end - begin < min_res)
                    min_res = end - (head = begin);
                if(map[s[begin++]] ++ == 0)
                    counter ++;
            }
        }
        return min_res == INT_MAX ? "" : s.substr(head, min_res);
    }
};