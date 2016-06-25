#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool is_valid(vector<string>& one_solution, int row, int col, int n)
    {
        //row from 0 to row-1
        for(int i = 0; i < row; i++)
        {
            if(one_solution[i][col] == 'Q')
            {
                return false;
            }
        }

        //对角线
        for(int x = row-1, y = col+1; x >= 0 && y < n; x--, y++)
        {
            if(one_solution[x][y] == 'Q')
                return false;
        }
        for(int x = row-1, y = col-1; x >=0 && y >= 0; x--, y--)
        {
            if(one_solution[x][y] == 'Q')
                return false;
        }
        return true;
    }

    void solve(int n, vector<vector<string> >& result, vector<string>& one_solution, int row)
    {
        if(row == n)
        {
            result.push_back(one_solution);
            return;
        }

        for(int i = 0; i < n; i++)
        {
           if(is_valid(one_solution, row, i, n))
           {
                one_solution[row][i] = 'Q';
                solve(n, result, one_solution, row+1);
                one_solution[row][i] = '.';  //backtrace
           }
        }
        return;
    }

    vector<vector<string> > solveNQueens(int n) 
    {
        vector<vector<string> > result;
        vector<string> one_solution(n,string(n,'.'));
        solve(n, result, one_solution, 0);
        return result;
    }
};