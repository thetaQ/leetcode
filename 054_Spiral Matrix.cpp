#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:  
    void print_a_circle(vector<int>& result, vector<vector<int> >& matrix, int rows, int cols, int start)
    {
        //右下角的坐标
        int endx = cols - 1 - start;
        int endy = rows - 1 - start;
        
        //top
        for(int i = start; i <= endx; i++)
        {
            result.push_back(matrix[start][i]);
        }
        
        //right
        if(start < endy)
        {
            for(int i = start + 1; i <= endy; i++)
            {
                result.push_back(matrix[i][endx]);
            }
        }
      
        //bottle
        if(start < endx && start < endy)
        {
            for(int i = endx - 1; i >= start; i--)
            {
                result.push_back(matrix[endy][i]);
            }
        }

        if(start < endx && start < endy - 1)
        {
            for(int i = endy - 1; i >= start + 1; i--)
            {
                result.push_back(matrix[i][start]);
            }
        }
    }
    
    vector<int> spiralOrder(vector<vector<int> >& matrix)
    {
        vector<int> result;
        int rows = matrix.size();
        if(rows <= 0)
            return result;
        int cols = matrix[0].size();
        if(cols <= 0)
            return result;
        
        int start = 0;
        while(cols > start*2 && rows > start*2)
        {
            print_a_circle(result, matrix, rows, cols, start);
            start ++;
        }
        return result;
    }
};