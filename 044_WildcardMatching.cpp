#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    
    //solution one: O(n)
    bool isMatch(const char *s, const char *p) {
        if(s == NULL || p == NULL)
            return false;
        const char *pp = NULL, *ss = NULL;
        while(*s != '\0')
        {
            if(*s == *p || *p == '?')
            {
                s++;
                p++;
                continue;
            }
            
            if(*p == '*')
            {
                pp = p ++;
                ss = s;
                continue;
            }
            
            //不匹配时
            if(pp != NULL)
            {
                p = pp + 1;
                s = ss + 1;
                ss ++;
                continue;
            }
            return false;
        }
        
        while(*p == '*')
            p++;
        return *p == '\0';
    }


    //solution two： DP
    bool isMatch(string s, string p)
    {
        vector<vector<bool> > dp(s.size()+1, vector<bool>(p.size()+1, false));
        dp[0][0] = true;

        for(int j = 1; j <= p.size(); j++)
        {
            if(p[j-1] == '*')
                dp[0][j] = true;
            else
                break;
        }

        for(int i = 1; i <= s.size(); i++)
        {
            for(int j = 1; j <= p.size(); j++)
            {
                if(p[j-1] == '*')
                {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else
                {
                    dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '?');
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};