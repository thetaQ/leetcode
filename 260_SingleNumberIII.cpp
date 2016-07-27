#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        int all_xor = 0;
        for(int num: nums)
        {
            all_xor ^= num;
        }
        if(all_xor == 0)
            return vector<int>();
        
        //find one bit int all_xor
        int mask = all_xor & ~(all_xor - 1);
        int x = 0, y = 0;
        for(int num: nums)
        {
            if(num & mask)
                x ^= num;
            else
                y ^= num;
        }
        vector<int> result(2);
        result[0] = x;
        result[1] = y;
        return result;
    }
};