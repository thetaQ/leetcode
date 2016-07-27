#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid)
    {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();

        vector<vector<int> > paths(rows, vector<int>(cols, 0));
        for(int j = 0; j < cols; j++)
        {
            if(obstacleGrid[0][j] != 1)
                paths[0][j] = 1;
            else
                break;
        }
        for(int i = 0; i < rows; i++)
        {
            if(obstacleGrid[i][0] != 1)
                paths[i][0] = 1;
            else
                break;
        }

        for(int i = 1; i < rows; i++)
        {
            for(int j = 1; j < cols; j++)
            {
                if(obstacleGrid[i][j] != 1)
                    paths[i][j] = paths[i-1][j] + paths[i][j-1];
            }
        }
        return paths[rows-1][cols-1];
    }
};