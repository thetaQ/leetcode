#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int row_start = 0, col_start = cols - 1;
        while(row_start < rows && col_start >= 0)
        {
            if(target < matrix[row_start][col_start])
            {
                col_start --;
            }
            else if(target > matrix[row_start][col_start])
            {
                row_start ++;
            }
            else
                return true;
        }
        return false;
    }
};