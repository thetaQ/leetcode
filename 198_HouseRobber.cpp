#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:

    //动态规划思想，dp[i]表示从[0-i]所能抢劫的最大钱
    //如果此次不抢，dp[i+1] = dp[i]
    //如果此次抢，则dp[i+1] = dp[i-1] + nums[i];
    int rob(vector<int>& nums) 
    {
        int size = nums.size();
        if(size == 0)
            return 0;
        int dp[size+1] = {0};
        dp[1] = nums[0];
        for(int i = 1; i < size; i++)
        {
            dp[i + 1] = max(dp[i], dp[i-1] + nums[i]);
        }
        return dp[size];
    }
};

int main(void)
{
    Solution solution;
    vector<int> nums = {2, 1, 4, 5, 3, 6};
    cout << solution.rob(nums) << endl;
    return 0;
}