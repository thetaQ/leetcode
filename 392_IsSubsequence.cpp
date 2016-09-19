#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t)
    {
        int s_index = 0, t_index = 0;
        while(s_index < s.size())
        {
            //从t中寻找s[s_index]
            while(t_index < t.size() && t[t_index] != s[s_index])
                t_index ++;
            if(t_index == t.size())
                break;
            s_index ++;
            t_index ++;
        }
        return s_index == s.size();
    }


    //动态规划法，内存溢出
    bool isSubsequence_2(string s, string t)
    {
        if(s.size() == 0)
            return true;
        if(t.size() == 0)
            return false;
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(t.size() + 1));
        for(int i = 0; i < t.size() + 1; i ++)
        {
            dp[0][i] = true;
        }
        for(int i = 1; i <= s.size(); i++)
        {
            for(int j = 1; j <= t.size(); j++)
            {
                if(s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
        return dp[s.size()][t.size()];
    }
};