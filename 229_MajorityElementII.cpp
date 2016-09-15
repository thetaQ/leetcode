#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        vector<int> res;
        
        if(nums.size() == 0)
            return res;
        
        int candidate1 = nums[0], candidate2 = nums[0];
        int count1 = 1, count2 = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            if(candidate1 == nums[i])
            {
                count1 ++;
            }
            else if(candidate2 == nums[i])
            {
                count2 ++;
            }
            else if(count1 == 0)
            {
                candidate1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0)
            {
                candidate2 = nums[i];
                count2 = 1;
            }
            else
            {
                count1 --;
                count2 --;
            }
        }
        
        count1 = 0, count2 = 0;
        for(auto num: nums)
        {
            if(num == candidate1)
            {
                count1 ++;
            }
            else if(num == candidate2)
            {
                count2 ++;
            }
        }
        if(count1 > nums.size()/3)
        {
            res.push_back(candidate1);
        }
        if(count2 > nums.size()/3)
        {
            res.push_back(candidate2);
        }
        return res;
    }
};