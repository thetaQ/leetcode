#include <iostream>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n)
    {
        int ugly_num[n];
        ugly_num[0] = 1;

        int index2 = 0, index3 = 0, index5 = 0;
        int curr = 1;
        while(curr < n)
        {
            ugly_num[curr] = min(min(ugly_num[index2]*2, ugly_num[index3]*3), ugly_num[index5]*5);
            while(ugly_num[index2]*2 <= ugly_num[curr])
                index2 ++;
            while(ugly_num[index3]*3 <= ugly_num[curr])
                index3 ++;
            while(ugly_num[index5]*5 <= ugly_num[curr])
                index5 ++;
            curr ++;
        }
        return ugly_num[n-1];
    }
};