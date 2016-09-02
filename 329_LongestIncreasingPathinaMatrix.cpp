#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> visited;
public:
    int dfs(vector<vector<int>>& matrix, int rows, int cols, int row, int col)
    {
        if(row < 0 || row >= rows || col < 0 || col >= cols)
        {
            return 0;
        }
        
        if(visited[row][col])
        {
            return visited[row][col];
        }
        int left = 0, right = 0, up = 0, down = 0;
        if(row > 0 && matrix[row][col] < matrix[row-1][col])
        {
            up = dfs(matrix, rows, cols, row-1, col);
        }
        if(row < rows - 1 && matrix[row][col] < matrix[row+1][col])
        {
            down = dfs(matrix, rows, cols, row+1, col);
        }
        if(col > 0 && matrix[row][col] < matrix[row][col-1])
        {
            left = dfs(matrix, rows, cols, row, col-1);
        }
        if(col < cols - 1 && matrix[row][col] < matrix[row][col+1])
        {
            right = dfs(matrix, rows, cols, row, col+1);
        }
        visited[row][col] = max(max(left, right), max(up, down)) + 1;
        return visited[row][col];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        int rows = matrix.size();
        if(rows == 0)
            return 0;
        int cols = matrix[0].size();
        if(cols == 0)
            return 0;
        
        vector<vector<int>> tmp(rows, vector<int>(cols, 0));
        visited = tmp;
        int max_len = INT_MIN;
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                max_len = max(max_len, dfs(matrix, rows, cols, i, j));
            }
        }
        return max_len;
    }
};