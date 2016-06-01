#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:

    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        unordered_map<int, int> mm;
        unsigned long size = nums.size();
        for(int i = 0; i < size; i++)
        {
            unordered_map<int, int>::iterator it = mm.find(nums[i]);
            if(it == mm.end())
            {
                //do not find
                mm[nums[i]] = i;
            }
            else
            {
                if(i - mm[nums[i]] <= k)
                    return true;
                else
                    mm[nums[i]] = i;
            }
        }
        return false;
    }
};