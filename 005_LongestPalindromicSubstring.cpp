#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int expand(string& s, int start, int end)
    {
        while(start >= 0 && end < s.size() && s[start] == s[end])
        {
            start --;
            end ++;
        }
        return end - start - 1;
    }
    
    string longestPalindrome(string s)
    {
        if(s.size() == 0)
            return "";
        int max_len = 1;
        int max_start = 0;
        for(int i = 0; i < s.size() - 1; ++i)
        {
            int len1 = expand(s, i, i);
            int len2 = expand(s, i, i + 1);
            if(max_len < len1)
            {
                max_len = len1;
                max_start = i - len1/2;
            }
            if(max_len < len2)
            {
                max_len = len2;
                max_start = i - len2/2 + 1;
            }
        }
        return s.substr(max_start, max_len);
    }
};