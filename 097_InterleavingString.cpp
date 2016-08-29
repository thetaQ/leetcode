#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:

    //DP
    bool isInterleave(string s1, string s2, string s3)
    {
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        if(len1 + len2 != len3)
            return false;
        
        vector<vector<bool> > dp(len1 + 1, vector<bool>(len2 + 1, false));
        dp[0][0] = true;
        
        for(int t = 1; t <= len3; t ++)
        {
            for(int i = max(t - len2, 0); i <= len1 && i <= t; i++)
            {
                int j = t - i;
                dp[i][j] = j > 0 && dp[i][j-1] && s3[t-1] == s2[j-1] ||
                           i > 0 && dp[i-1][j] && s3[t-1] == s1[i-1];
            }
        }
        return dp[len1][len2];
    }
};