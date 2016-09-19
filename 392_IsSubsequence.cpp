#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t)
    {
        int s_index = 0, t_index = 0;
        while(s_index < s.size())
        {
            //从t中寻找s[s_index]
            while(t_index < t.size() && t[t_index] != s[s_index])
                t_index ++;
            if(t_index == t.size())
                break;
            s_index ++;
            t_index ++;
        }
        return s_index == s.size();
    }
};