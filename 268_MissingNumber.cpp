#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //方法一：数学
    int missingNumber(vector<int>& nums)
    {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        return nums.size() * (nums.size() + 1) / 2 - sum;
    }

    //方法二：异或
    int missingNumber_2(vector<int>& nums)
    {
        int res = nums.size();
        for(int i = 0; i < nums.size(); i++)
        {
            res ^= i;
            res ^= nums[i];
        }
        return res;
    }

    //方法三：如果是有序的数组，则可以二分
    int missingNumber_3(vector<int>& nums)
    {
        int start = 0, end = nums.size();
        while(start < end)
        {
            int mid = start + (end - start) / 2;
            if(nums[mid] > mid)
            {
                end = mid;
            }
            else
            {
                start = mid + 1;
            }
        }
        return start;
    }
};