#include <iostream>
using namespace std;
class Solution {
public:
    int trailingZeroes(int n)
    {
        int cnt = 0;
        while(n > 0)
        {
            cnt += n / 5;
            n /= 5;
        }
        return cnt;
    }
};