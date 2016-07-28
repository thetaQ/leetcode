#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target)
    {
        if(target == 0)
            return 1;
        int ways = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            //choose nums[i]
            if(target < nums[i])
                continue;
            int new_target = target - nums[i];
            if(cache.find(new_target) != cache.end())
            {
                ways += cache[new_target];
            }
            else
            {
                int new_ways = combinationSum4(nums, new_target);
                cache[new_target] = new_ways;
                ways += new_ways;
            }
        }
        return ways;
    }
private:
    unordered_map<int, int> cache;
};