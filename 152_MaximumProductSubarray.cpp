#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int size = nums.size();

        int max_local = nums[0];
        int min_local = nums[0];
        int max_global = nums[0];

        for(int i = 1; i < size; i++)
        {
            int a = max_local * nums[i];
            int b = min_local * nums[i];

            max_local = max(max(a, b), nums[i]);
            min_local = min(min(a, b), nums[i]);
            max_global = max(max_global, max_local);
        }
        return max_global;    
    }
};