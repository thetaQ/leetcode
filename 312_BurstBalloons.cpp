#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        //dp[left][right]表示从left到right的最大硬币值
        vector<vector<int> > dp(n+2, vector<int>(n+2, 0));
        for(int len = 1; len <= n; len ++)
        {
            for(int left = 1; left + len - 1 <= n; left ++)
            {
                int right = left + len - 1;
                for(int k = left; k <= right; k++)  //在区间[left, right]中，最后一个剩下的是k
                {
                    dp[left][right] = max(dp[left][right], nums[left-1] * nums[k] * nums[right + 1] + dp[left][k-1] + dp[k+1][right]);
                }
            }
        }
        return dp[1][n];
    }
};