#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        unsigned int size = nums.size();
        if(size == 0 || k > size)
            return vector<int>();

        vector<int> result;
        deque<int> index;
        for(unsigned int i = 0; i < k; i++)
        {
            while(!index.empty() && nums[i] >= nums[index.back()])
                index.pop_back();
            index.push_back(i);
        }

        for(unsigned int i = k; i < size; i++)
        {
            result.push_back(nums[index.front()]);
            while(!index.empty() && nums[i] > nums[index.back()])
                index.pop_back();
            if(!index.empty() && index.front() <= (int)(i - k))
                index.pop_front();
            index.push_back(i);
        }
        result.push_back(nums[index.front()]);
        return result;
    }
};