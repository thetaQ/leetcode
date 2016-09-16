#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        int rows = matrix.size();
        int cols = rows == 0 ? 0 : matrix[0].size();
        vector<bool> row_zero(rows, false);
        vector<bool> col_zero(cols, false);
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(matrix[i][j] == 0)
                {
                    row_zero[i] = true;
                    col_zero[j] = true;
                }
            }
        }
        
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(row_zero[i] || col_zero[j])
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};