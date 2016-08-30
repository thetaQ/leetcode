#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows = dungeon.size();
        if(rows == 0)
            return 0;
        int cols = dungeon[0].size();
        if(cols == 0)
            return 0;
        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, INT_MAX));
        dp[rows][cols-1] = 1; //表示在最后一个格子必须活下来
        dp[rows-1][cols] = 1;
        for(int i = rows - 1; i >= 0; i--)
        {
            for(int j = cols - 1; j >= 0; j--)
            {
                int min_hp = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
                dp[i][j] = min_hp <= 0 ? 1 : min_hp;
            }
        }
        return dp[0][0];
    }
};