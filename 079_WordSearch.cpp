#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    bool search(vector<vector<char> >& board, int rows, int cols, string& word,
                int row, int col, int cur_index, vector<vector<bool> >& visited)
    {
        
        if(cur_index == word.size())
        {
            return true;
        }
        if(row < 0 || row >= rows)
            return cur_index == word.size();
        if(col < 0 || col >= cols)
            return cur_index == word.size();
        
        
        
        if(board[row][col] != word[cur_index])
        {
            return false;
        }
        
        if(visited[row][col] == true)
            return false;
        
        int res = false;
        visited[row][col] = true;
        res = res || search(board, rows, cols, word, row+1, col, cur_index+1, visited) ||
                     search(board, rows, cols, word, row-1, col, cur_index+1, visited) ||
                     search(board, rows, cols, word, row, col+1, cur_index+1, visited) ||
                     search(board, rows, cols, word, row, col-1, cur_index+1, visited);
        visited[row][col] = false;
        return res;
    }

    bool exist(vector<vector<char> >& board, string word) {
        int rows = board.size();
        if(rows == 0)
            return false;
        int cols = board[0].size();
        if(cols == 0)
            return 0;
        if(word.size() == 0)
            return true;
        
        vector<vector<bool> > visited(rows, vector<bool>(cols, false));
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(search(board, rows, cols, word, i, j, 0, visited) == true)
                    return true;
            }
        }
        return false;
    }
};