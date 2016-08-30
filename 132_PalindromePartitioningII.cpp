#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int minCut(string s) {
        vector<int> dp(s.size(), 0);
        vector<vector<bool> > is_pal(s.size(), vector<bool>(s.size(), false));
        
        for(int i = 0; i < s.size(); i++)
        {
            int min_cut = i;
            for(int j = 0; j <= i; j++)
            {
                if(s[j] == s[i] && (j + 1 > i - 1 || is_pal[j + 1][i - 1] == true))
                {
                    is_pal[j][i] = true;
                    min_cut = (j == 0 ? 0 : min(min_cut, dp[j - 1] + 1));
                }
            }
            dp[i] = min_cut;
        }
        return dp[s.size() - 1];
    }
};