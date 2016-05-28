#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<int> line1 = {1};
        vector<int> line2 = {1, 1};
        vector<vector<int>> result;
        if(numRows == 0)
            return result;
        else if(numRows == 1)
        {
            result.push_back(line1);
            return result;
        }
        else if(numRows >= 2)
        {
            result.push_back(line1);
            result.push_back(line2);
        }
        
        for(int i = 2; i < numRows; ++i)
        {
            vector<int> v;
            v.push_back(1);
            unsigned long size = result[i-1].size();
            for(int j = 1; j < size; j++)
            {
                v.push_back(result[i-1][j-1] + result[i-1][j]);
            }
            v.push_back(1);
            result.push_back(v);
        }
        return result;
    }
};