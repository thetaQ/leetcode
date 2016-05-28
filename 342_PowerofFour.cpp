#include <iostream>
using namespace std;

class Solution {
public: 
    //solution one: iterative
    bool isPowerOfFour(int num)
    {
        if(num <= 0)
            return false;
        while(num != 1)
        {
            if(num % 4 == 0)
                num >>= 2;
            else
                return false;
        }
        return true;
    }
    
    //solution two: trick
    bool isPowerOfFour_2(int num)
    {
        if(num &(num - 1))
            return false;
        if(num & 0x55555555)
            return true;
        return false;
    }
};