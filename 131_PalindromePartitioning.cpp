#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool is_pal(string s)
    {
        int start = 0, end = s.size()-1;
        while(start < end)
        {
            if(s[start] != s[end])
                return false;
            start ++;
            end --;
        }
        return true;
    }
    
    void partition(vector<vector<string> >& result, string s, vector<string>& one_solution)
    {
        if(s.size() == 0)
        {
            result.push_back(one_solution);
            return;
        }
        
        for(int i = 1; i <= s.size(); i++)
        {
            string cut = s.substr(0, i);
            string left = s.substr(i);
            
            if(is_pal(cut))
            {
                one_solution.push_back(cut);
                partition(result, left, one_solution);
                one_solution.pop_back();
            }
        }
    }
    
    vector<vector<string> > partition(string s) {
        vector<vector<string> > res;
        vector<string> one_solution;
        partition(res, s, one_solution);
        return res;
    }

};