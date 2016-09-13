#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board)
    {
        int rows = board.size();
        int cols = rows ? board[0].size() : 0;

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                //计算周围的细胞情况
                int count = 0;
                for(int s = max(0, i - 1); s < min(i + 2, rows); s++)
                {
                    for(int t = max(0, j - 1); t < min(j + 2, cols); t++)
                    {
                        if(board[s][t] & 1)
                            count ++;
                    }
                }
                count -= board[i][j];

                //如果周围有三个活的，无论自己是死是活，下一轮都是活
                //如果周围有两个活的，并且自身是活的，下一轮是活的
                if(count == 3 || (count == 2 && board[i][j]))
                    board[i][j] |= 2;
            }
        }

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                board[i][j] >>= 1;
            }
        }
    }
};