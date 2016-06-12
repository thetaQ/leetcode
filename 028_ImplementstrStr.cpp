#include <iostream>
#include <string>
using namespace std;

class Solution {
public:

    /*
    * first solution: iterative
    */
    int strStr(string haystack, string needle)
    {
        int lenh = haystack.size();
        int lenn = needle.size();
        if(lenh < lenn)
            return -1;
        int size = lenh - lenn;
        for(int i = 0; i <= size; ++i)
        {
            bool exist = true;
            for(int j = 0; j < lenn; j++)
            {
                if(haystack[i+j] != needle[j])
                {
                    exist = false;
                    break;
                }
            }
            if(exist)
            {
                return i;
            }
        }
        return -1;
    }



};