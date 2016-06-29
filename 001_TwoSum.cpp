#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static bool compareNum(pair<int, size_t>& l, pair<int, size_t>& r)
    {
        return l.first < r.first;
    }

    vector<int> twoSum(vector<int>& nums, int target) 
    {
        size_t size = nums.size();
        vector<pair<int, size_t> > sorted_nums(size, make_pair(0, 0));
        for(size_t i = 0; i < size; i++)
        {
            sorted_nums[i].first = nums[i];
            sorted_nums[i].second = i;
        }
        /* sort the vector first */
        sort(sorted_nums.begin(), sorted_nums.end(), compareNum);

        size_t first = 0, last = size - 1;
        vector<int> result(2, 0);     
        while(first < last)
        {
            int sum = sorted_nums[first].first + sorted_nums[last].first;
            if(sum == target)
            {
                result.push_back(sorted_nums[first].second);
                result.push_back(sorted_nums[last].second);
                break;
            }
            else if(sum < target)
            {
                first ++;
            }
            else
            {
                last --;
            }
        }
        return result;
    }
};