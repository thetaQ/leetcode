#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numDistinct(string S, string T) {
        vector<vector<int>> dp(S.size()+1, vector<int>(T.size()+1, 0));
        
        //如果T是空，则空字符串也是S的子序列
        for(int i = 0; i < S.size()+1; i++)
        {
            dp[i][0] = 1;
        }
        
        for(int i = 1; i < S.size()+1; i++)
        {
            for(int j = 1; j < T.size()+1; j++)
            {
                if(S[i-1] == T[j-1])
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[S.size()][T.size()];
    }
};