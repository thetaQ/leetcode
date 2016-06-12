#include <iostream>
#include <string>
using namespace std;

class Solution {
public:

    /*
    * first solution: brute force
    */
    int strStr(string haystack, string needle)
    {
        int lenh = haystack.size();
        int lenn = needle.size();
        if(lenh < lenn)
            return -1;
        int size = lenh - lenn;
        int i, j;
        for(i = 0; i <= size; ++i)
        {
            for(j = 0; j < lenn; j++)
            {
                if(haystack[i+j] != needle[j])
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

    /*
    * second solution: KMP
    */
    int strStr_KMP(string haystack, string needle)
    {

    }

};