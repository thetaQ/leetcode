#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int helper(vector<int>& nums, int start, int end)
    {
        if(start >= end)
        {
            return nums[start];
        }
        
        if(nums[start] < nums[end])
        {
            return nums[start];
        }
        else
        {
            int mid = start + (end - start) / 2;
            if(nums[mid] > nums[end])
            {
                return helper(nums, mid+1, end);
            }
            else if(nums[mid] < nums[end])
            {
                return helper(nums, start, mid);
            }
            else
            {
                return helper(nums, start+1, end-1);
            }
        }
    }

    int findMin(vector<int>& nums) 
    {
        return helper(nums, 0, nums.size()-1);
    }
};