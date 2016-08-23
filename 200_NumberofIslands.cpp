#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    void dfs(vector<vector<char>>& grid, int rows, int cols, int i, int j)
    {
        if(i < 0 || i >= rows)
            return;
        if(j < 0 || j >= cols)
            return;
        if(grid[i][j] == '1')
        {
            grid[i][j] = '2';
            dfs(grid, rows, cols, i-1, j);
            dfs(grid, rows, cols, i+1, j);
            dfs(grid, rows, cols, i, j-1);
            dfs(grid, rows, cols, i, j+1);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if(rows == 0)
            return 0;
        int cols = grid[0].size();
        if(cols == 0)
            return 0;
        int count = 0;
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == '1')
                {
                    dfs(grid, rows, cols, i, j);
                    count ++;
                }
            }
        }
        return count;
    }
};