#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        //dp[i]表示以nums[i]为结尾的最长递增子序列的长度
        int size = nums.size();
        if(size == 0)
            return 0;
        vector<int> dp(size, 1);
        int max_len = 1;
        for(int i = 1; i < size; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            max_len = max(max_len, dp[i]);
        }
        return max_len;
    }
};