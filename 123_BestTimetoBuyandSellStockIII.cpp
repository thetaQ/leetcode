#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)
            return 0;
            
        int K = 2;
        vector<vector<int>> dp(K+1, vector<int>(prices.size(), 0));
        
        for(int k = 1; k <= K; k++)
        {
            int tmp_max = dp[k-1][0] - prices[0];
            for(int i = 1; i < prices.size(); i++)
            {
                dp[k][i] = max(dp[k][i-1], tmp_max + prices[i]);
                tmp_max = max(tmp_max, dp[k-1][i] - prices[i]);
            }
        }
        return dp[K][prices.size()-1];
    }
};