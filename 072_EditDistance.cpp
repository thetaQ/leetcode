#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2)
    {
        size_t size1 = word1.size();
        size_t size2 = word2.size();

        if(size1 == 0)
            return size2;
        if(size2 == 0)
            return size1;
        
        vector<vector<int> > dp(size1+1, vector<int>(size2+1, 0));
        for(int i = 1; i <= size1; i++)
        {
            dp[i][0] = i;
        }

        for(int j = 1; j <= size2; j++)
        {
            dp[0][j] = j;
        }
        for(int i = 1; i <= size1; i++)
        {
            for(int j = 1; j <= size2; j++)
            {
                int cost = 0;
                if(word1[i-1] != word2[j-1])
                {
                    cost = 1;
                }
                dp[i][j] = min(min(dp[i-1][j]+1, dp[i][j-1]+1), dp[i-1][j-1]+cost);
            }
        }
        return dp[size1][size2];
    }
};