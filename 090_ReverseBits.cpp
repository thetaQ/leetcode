#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {
        stack<int> bits;
        while(n)
        {
            bits.push(n & 0x01);
            n >>= 1;
        }
        while(bits.size() < 32)
            bits.push(0);
        uint32_t result = 0;
        int i = 0;
        while(!bits.empty())
        {
            result += bits.top() << i;
            i ++;
            bits.pop();
        }
        return result;
    }
};