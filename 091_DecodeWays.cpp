#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s)
    {
        int size = s.size();
        if(size == 0)
            return 0;
        int dp[size] = {0};
        dp[size-1] = s[size-1]!='0';
        if(size >= 2)
        {
            if(s[size-2] == '0')
                dp[size-2] = 0;
            else
            {
                int digit = (s[size-2]-'0')*10 + s[size-1]-'0';
                if(digit > 0 && digit <= 26)
                    dp[size-2] = dp[size-1]+1;
                else
                    dp[size-2] = dp[size-1];
            }
        }
        
        for(int i = size - 3; i >= 0; --i)
        {
            if(s[i] == '0')
                continue;
            int digit = (s[i]-'0')*10 + s[i+1]-'0';
            dp[i] = dp[i+1] + dp[i+2] * ((digit > 0 && digit <= 26) ? 1 : 0);
        }
        return dp[0];
    }
};