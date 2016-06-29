#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:

    //solution one: dp
    int maxSubArray(vector<int>& nums)
    {
        int size = nums.size();
        int dp[size];
        dp[0] = nums[0];
        int max_sum = nums[0];
        for(int i = 0; i < size-1; i++)
        {
            if(dp[i] >= 0)
            {
                dp[i+1] = dp[i] + nums[i+1];
                max_sum = max(max_sum, dp[i+1]);
            }
            else
            {
                dp[i+1] = nums[i+1];
                max_sum = max(max_sum, dp[i+1]);
            }
        }
        return max_sum;
    }

    //solution two
    int maxSubArray_2(vector<int>& nums)
    {
        int sum = 0, max_sum = nums[0];
        int size = nums.size();
        for(int i = 0; i < size; i++)
        {
            sum += nums[i];
            if(max_sum < sum)
            {
                max_sum = sum;
            } 
            
            if(sum < 0)
            {
                sum = 0;
            }
        }
        return max_sum;
    }
};