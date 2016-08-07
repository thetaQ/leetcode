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

    //Sunday 算法
    int strStr_2(string haystack, string needle)
    {
        int hsize = haystack.size();
        int nsize = needle.size();
        int next[26] = {0};
        for(int i = 0; i < 26; ++i)
            next[i] = nsize + 1;
        for(int i = 0; i < nsize; ++i)
            next[needle[i]-'a'] = nsize - i;
            
        int pos = 0;
        while(pos < hsize - nsize + 1)
        {
            int i = pos;
            int j;
            for(j = 0; j < nsize; ++j, ++i)
            {
                if(haystack[i] != needle[j])
                {
                    pos += next[haystack[pos+nsize]-'a'];
                    break;
                }
            }
            if(j == nsize)
                return pos;
        }
        return -1;
    }
};