#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {
        vector<int> result;
        if(rowIndex == 0)
        {
            result.push_back(1);
            return result;
        } 
        else
        {
            result.push_back(1);
            while(rowIndex --)
            {
                int size = result.size();
                for(int i = size - 1; i >= 1; i--)
                {
                    result[i] += result[i-1];
                }
                result.push_back(1);
            }
        }
        return result;
    }
};