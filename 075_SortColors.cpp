#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    void swap(vector<int>& nums, int a, int b)
    {
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }

    void sortColors(vector<int>& nums) 
    {
        int l = 0, r = nums.size() - 1;
        int index = 0;
        while(index <= r)
        {
            if(nums[index] == 0)
            {
                swap(nums, index, l++);
            }
            else if(nums[index] == 2)
            {
                swap(nums, index--, r--);
            }
        }
    }
};