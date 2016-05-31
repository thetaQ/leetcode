#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    bool isValid_row(vector<vector<char> >& board, int row)
    {
        int ht[9]  = {0};
        for(int i = 0; i < 9; ++i)
        {
            if(board[row][i] != '.')
            {
                if(ht[board[row][i]-'1'] == 0)
                {
                    ht[board[row][i]-'1'] = 1;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValid_col(vector<vector<char> >& board, int col)
    {
        int ht[9] = {0};
        for(int i = 0; i < 9; ++i)
        {
            if(board[i][col] != '.')
            {
                if(ht[board[i][col]-'1'] == 0)
                {
                    ht[board[i][col]-'1'] = 1;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValid_square(vector<vector<char> >& board, int row, int col)
    {
        int ht[9] = {0};
        for(int i = row; i < row + 3; ++i)
        {
            for(int j = col; i < col + 3; ++j)
            {
                if(board[i][j] != '.')
                {
                    if(ht[board[i][j]-'1'] == 0)
                    {
                        ht[board[i][j]-'1'] = 1;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char> >& board)
    {
        for(int i = 0; i < 9; ++i)
        {
            if(!isValid_row(board, i))
                return false;
            if(!isValid_col(board, i))
                return false;
            if(!isValid_square(board, 3*(i/3), 3*(i%3)))
                return false;
        }
        return true;
    }
};

