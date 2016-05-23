#include <iostream>

using namespace std;

class Solution {
public:

    /* solution one: recursion */
    bool isPowerOfThree(int n)
    {
        if(n <= 0) 
            return false;
        if(n == 1)
            return true;
        if(n%3 == 0)
            return isPowerOfThree(n/3);
        return false; 
    }


    /* solution two: iteration */
    bool isPowerOfThree_2(int n)
    {
        if(n <= 0)
            return false;
        while(n != 1) 
        {
            if(n%3 == 0) 
            {
                n /= 3; 
            }
            else
            {
                return false; 
            }
        }
        return true;
    }

    /* solution three: other */
    bool isPowerOfThree_3(int n)
    {
        return n > 0 && 1162261467%n == 0;
    }
    
};
