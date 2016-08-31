#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0)
            return 1;
        if(n == 1)
            return 10;
        if(n > 10)
            n = 10;
        int product = 1;
        vector<int> dp(11, 0);
        dp[0] = 1;
        dp[1] = 10;
        for(int i = 2; i <= n; i++)
        {
            product *= (10 - (i-1));
            dp[i] = dp[i-1] + 9 * product;
        }
        return dp[n];
    }
};