#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    //solution one
    bool isIsomorphic(string s, string t)
    {
        if(s.size() != t.size())
            return false;
        
        unordered_map<char, char> mm;
        set<char> ss;
        for(int i = 0; i < s.size(); ++i)
        {
            if(mm.find(s[i]) == mm.end())
            {
                if(ss.find(t[i]) == ss.end())
                {
                    mm[s[i]] = t[i];
                    ss.insert(t[i]);
                }
                else
                    return false;
            }
            else
            {
                if(mm[s[i]] != t[i])
                    return false;
            }
        }
        return true;
    }
    
    
    //solution two
    bool isIsomorphic_2(string s, string t)
    {
        if(s.size() != t.size())
            return false;
        vector<int> s_t(127, 0);
        vector<int> t_s(127, 0);
        
        for(int i = 0; i < s.size(); ++i)
        {
            if(s_t[s[i]] == 0 && t_s[t[i]] == 0)
            {
                s_t[s[i]] = t[i];
                t_s[t[i]] = s[i];
            }
            else if(s_t[s[i]] != t[i] || t_s[t[i]] != s[i])
                return false;
        }
        return true;
    }    
};