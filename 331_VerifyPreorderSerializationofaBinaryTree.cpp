#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> split(string str, char sep)
    {
        vector<string> result;
        if(str.size() == 0)
            return result;
        while(!str.empty())
        {
            int index = str.find_first_of(sep);
            if(index != -1)
            {
                result.push_back(str.substr(0, index));
                str = str.substr(index+1);
            }
            else
            {
                result.push_back(str);
                str.clear();
            }
        }
        return result;
    }

    bool isValidSerialization(string preorder) {
        if(preorder.size() == 0)
            return true;
        vector<string> strs = split(preorder, ',');
        int degree = -1;  //root has no indegree
        for(int i = 0; i < strs.size(); ++i)
        {
            degree ++;
            if(degree > 0)
                return false;
            if(strs[i] != "#")
                degree -= 2;
        }
        return degree == 0;
    }
};