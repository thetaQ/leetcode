#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums)
    {
        int start = 0, end = 0;
        int min_len = INT_MAX;
        int sum = 0;
        while(end < nums.size())
        {
            sum += nums[end ++];
            while(sum >= s)
            {
                min_len = min(min_len, end - start);
                sum -= nums[start ++];
            }
        }
        return min_len == INT_MAX ? 0:min_len;
    }
};