#include <iostream>
#include <stdint.h>

using namespace std;

class Solution {
public:

    //solution one: shift
    int hammingWeight(uint32_t n)
    {
        int cnt = 0;
        while(n > 0)        
        {
           cnt += n & 0x1;
           n >>= 1;
        }
        return cnt; 
    }


    //solution two: n&(n-1) -->set last one bit to zero
    int hammingWeight_2(uint32_t n)
    {
        int cnt = 0;
        while(n > 0)
        {
            n &= (n-1); 
            cnt ++;
        }
        return cnt;
    }
};


int main(void)
{
    Solution solution;
    cout << solution.hammingWeight(11) << endl;
    return 0;
}
