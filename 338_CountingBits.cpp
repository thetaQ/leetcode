#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1, 0);
        dp[1] = 1;
        int cur_2 = 2;
        int cur_num = 2;
        while(cur_num <= num)
        {
            for(cur_num = cur_2; cur_num < cur_2 * 2 && cur_num <= num; cur_num ++)
            {
                dp[cur_num] = dp[cur_num % cur_2] + 1;
            }
            cur_2 <<= 1;
        }
        return dp;
    }
};