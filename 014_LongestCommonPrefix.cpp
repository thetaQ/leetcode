#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    bool all_same_at_position(vector<string>& strs, int position)
    {
        if(position >= strs[0].size())
            return false;
        char c = strs[0][position];
        int size = strs.size();
        for(int i = 1; i < size; i++)
        {
            if(position >= strs[i].size())
                return false;
            if(c != strs[i][position])
                return false;
        }
        return true;
    }

    string longestCommonPrefix(vector<string>& strs)
    {
        if(strs.size() == 0)
            return string();
        int length = strs[0].size();
        string res;
        for(int i = 0; i < length; i++)
        {
            if(all_same_at_position(strs, i))
                res.push_back(strs[0][i]);
            else
                break;
        }
        return res;
    }
};