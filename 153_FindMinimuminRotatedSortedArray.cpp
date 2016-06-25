#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int helper(vector<int>&nums, int left, int right)
    {
        if(left == right)
        {
            return nums[left];
        }
        int mid = left + (right - left)/2;
        if(nums[mid] > nums[right])
        {
            //search right
            return helper(nums, mid + 1, right);
        }
        else
        {
            return helper(nums, left, mid);
        }
    }

    int findMin(vector<int>& nums) 
    {
        return helper(nums, 0, nums.size()-1);
    }
};