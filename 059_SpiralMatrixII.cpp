#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    void generateMatrixCore(vector<vector<int>>& matrix, int n, int& num, int start)
    {
        //右下角的坐标
        int end_x = n - start - 1;
        int end_y = end_x;
        
        for(int i = start; i <= end_x; i++)
        {
            matrix[start][i] = num ++;
        }

        if(start < end_y)
        {
            for(int i = start + 1; i <= end_y; i++)
            {
                matrix[i][end_x] = num ++;   
            }
        }
        
        if(start < end_x && start < end_y)
        {
            for(int i = end_x - 1; i >= start; i--)
            {
                matrix[end_x][i] = num ++;
            }
        }
        
        if(start < end_x && start < end_y - 1)
        {
            for(int i = end_y - 1; i >= start + 1; i--)
            {
                matrix[i][start] = num ++;
            }
        }
    }

    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> matrix(n, vector<int>(n));
        int num = 1;
        for(int start = 0; start * 2 < n; start ++)
        {
            generateMatrixCore(matrix, n, num, start);
        }
        return matrix;
    }
};