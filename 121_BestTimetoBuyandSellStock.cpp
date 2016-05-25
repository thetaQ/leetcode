#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int min_buy = 2147483647 , max_profit = -2147483648;
        if(prices.size() == 0)
            return 0;
        for(int price: prices)
        {
            if(price < min_buy)
                min_buy = price;
            if(max_profit < price - min_buy)
                max_profit = price - min_buy;
        }
        return max_profit;
    }
};

int main(void)
{
    Solution solution;
    vector<int> prices = {1, 4, 0, 3, 2};
    cout << solution.maxProfit(prices);
    return 0;
}