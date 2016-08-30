#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int quick_solve(vector<int>& prices)
    {
        int profit = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] > prices[i-1])
                profit += prices[i] - prices[i-1];
        }
        return profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        if(prices.size() <= 1)
            return 0;
        if(k >= prices.size() / 2)
        {
            return quick_solve(prices);
        }
        
        vector<vector<int>> dp(k+1, vector<int>(prices.size(), 0));
        
        for(int kk = 1; kk <= k; kk++)
        {
            int tmp_max = dp[kk-1][0] - prices[0];
            for(int i = 1; i < prices.size(); i++)
            {
                dp[kk][i] = max(dp[kk][i-1], tmp_max + prices[i]);
                tmp_max = max(tmp_max, dp[kk-1][i] - prices[i]);
            }
        }
        return dp[k][prices.size()-1];
    }
};