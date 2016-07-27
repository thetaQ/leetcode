#include <iostream>
using namespace std;

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n)
    {
        int start = 1, end = n;
        int ret;
        while(start < end)
        {
            int mid = start + (end - start) / 2;
            ret = guess(mid);
            if(ret > 0)
            {
                start = mid + 1;
            }
            else if(ret < 0)
            {
                end = mid - 1;
            }
            else
            {
                return mid;
            }
        }
        return start;
    }
};