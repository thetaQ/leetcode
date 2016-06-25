#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:

    /*
    * first solution: brute force
    */
    int strStr(string haystack, string pattern)
    {
        int lenh = haystack.size();
        int lenn = pattern.size();
        if(lenh < lenn)
            return -1;
        int size = lenh - lenn;
        int i, j;
        for(i = 0; i <= size; ++i)
        {
            for(j = 0; j < lenn; j++)
            {
                if(haystack[i+j] != pattern[j])
                {
                    break;
                }
            }
            if(j == lenn)
            {
                return i;
            }
        }
        return -1;
    }
};