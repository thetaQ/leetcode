#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        int result = 0;
        for(int i = 0; i < 32; i++)
        {
            int mask = 1 << i, one_cnt = 0;
            for(int num: nums)
            {
                if(num & mask)
                    one_cnt ++;
            }
            if(one_cnt % 3 == 1)
                result |= mask;
        }
        return result;
    }
};