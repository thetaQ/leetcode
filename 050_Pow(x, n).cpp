#include <iostream>
using namespace std;

class Solution {
public:
    
    bool double_equal(double x, double y)
    {
        if((x - y > -0.0000001) &&
            (x - y < 0.0000001))
            return true;
        return false;
    }

    double mpow(double x, unsigned int n)
    {
        if(n == 0)
            return 1;
        if(n == 1)
            return x;
        double result = mpow(x, n >> 1);
        result *= result;
        if(n & 0x1 == 1)
            result *= x;
        return result;
    }
    
    double myPow(double x, int n)
    {
        if(double_equal(x, 0.0) && n < 0)
            return 0.0;   //invalid input
        unsigned int exp = (unsigned int)n;
        if(n < 0)
            exp = (unsigned int)(-n);
        
        double result = mpow(x, exp);
        if(n < 0)
            result = 1.0/result;
        return result;
    }
};