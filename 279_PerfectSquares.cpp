#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        if(n == 0)
            return 0;
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++)
        {
            //计算dp[i]
            int min_num = INT_MAX;
            for(int j = 1; j * j <= i; j++)
            {
                min_num = min(min_num, dp[i - j * j] + 1);
            }
            dp[i] = min_num;
        }
        return dp[n];
    }
};