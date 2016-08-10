#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int size = nums.size();
        if(size == 0)
            return vector<int>();
        vector<int> result(size, 1);
        int tmp = 1;
        for(int i = 1; i < size; i++)
        {
            tmp *= nums[i-1];
            result[i] = tmp;
        }
        
        tmp = 1;
        for(int i = size - 2; i >= 0; i--)
        {
            tmp *= nums[i+1];
            result[i] *= tmp;
        }
        return result;
    }
};