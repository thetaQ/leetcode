#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2)
            return max(nums[0], nums[1]);
        
        //如果抢第一个，最后一个就不能抢
        vector<int> dp1(nums.size());
        dp1[0] = nums[0];
        dp1[1] = nums[0];
        for(int i = 2; i < nums.size() - 1; i ++)
        {
            dp1[i] = max(dp1[i-1], dp1[i-2] + nums[i]);
        }
        
        //不抢第一个，可以抢到最后一个
        vector<int> dp2(nums.size());
        dp2[0] = 0;
        dp2[1] = nums[1];
        for(int i = 1; i < nums.size(); i ++)
        {
            dp2[i] = max(dp2[i-1], dp2[i-2] + nums[i]);
        }
        
        return max(dp1[nums.size()-2], dp2[nums.size()-1]);
    }
};