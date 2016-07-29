#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {
        for(int i = nums.size()-1; i >= 1; i--)
        {
            //从尾部开始找找到第一个升序对
            if(nums[i] > nums[i-1])
            {
                int j = nums.size() - 1;
                for(; j > i - 1; j--)
                {
                    if(nums[j] > nums[i-1])
                        break;
                }
                swap(nums, j, i-1);
                reverse(nums, i, nums.size()-1);
                return;
            }
        }
        reverse(nums, 0, nums.size()-1);
    }
private:
    void swap(vector<int>&nums, int a, int b)
    {
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }

    void reverse(vector<int>& nums, int start, int end)
    {
        int tmp;
        while(start < end)
        {
            swap(nums, start, end);
            start ++;
            end --;
        }
    }
};