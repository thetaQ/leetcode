#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:    
    void dfs(vector<vector<char>>& board, int rows, int cols, int row, int col)
    {
        if(board[row][col] == 'O')
        {
            board[row][col] = 'o';
            if(row > 1)
                dfs(board, rows, cols, row - 1, col);
            if(col > 1)
                dfs(board, rows, cols, row, col - 1);
            if(row < rows - 1)
                dfs(board, rows, cols, row + 1, col);
            if(col < cols - 1)
                dfs(board, rows, cols, row, col + 1);
        }
    }

    void solve(vector<vector<char>>& board)
    {
        int rows = board.size();
        if(rows == 0)
            return;
        int cols = board[0].size();
        if(cols == 0)
            return;
 
        for(int i = 0; i < cols; i++)
        {
            dfs(board, rows, cols, 0, i);
            if(rows > 1)
            {
                dfs(board, rows, cols, rows - 1, i);
            }
        }
        for(int i = 1; i < rows - 1; i++)
        {
            dfs(board, rows, cols, i, 0);
            if(cols > 1)
            {
                dfs(board, rows, cols, i, cols - 1);
            }
        }
        
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == 'o')
                    board[i][j] = 'O';
            }
        }
    }
};