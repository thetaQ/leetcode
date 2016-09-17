#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        if(nums.size() < 3)
            return 0;
        int res = 0, min_diff = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int a = 0; a < nums.size(); a++)
        {
            if(a > 0 && nums[a] == nums[a - 1])
                a ++;
            int b = a + 1;
            int c = nums.size() - 1;
            while(b < c)
            {
                int sum = nums[a] + nums[b] + nums[c];
                if(sum == target)
                    return sum;
                if(sum < target)
                {
                    if(target - sum < min_diff)
                    {
                        min_diff = target - sum;
                        res = sum;
                    }
                    b ++;
                }
                else
                {
                    if(sum - target < min_diff)
                    {
                        min_diff = sum - target;
                        res = sum;
                    }
                    c --;
                }
            }
        }
        return res;
    }
};