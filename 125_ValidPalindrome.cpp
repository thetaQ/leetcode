#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s)
    {
        int size = s.size();
        if(s.empty() || size == 0)
            return true;
        
        int start = 0, end = size - 1;
        while(start < end)
        {
            while(start < size && !isalpha(s[start]) && !isdigit(s[start]))
                start ++;
            if(start == size)
                break;
            while(end >= 0 && !isalpha(s[end]) && !isdigit(s[end]))
                end --;
            if(end == -1)
                break;
            if(start >= end)
                break;
            if(tolower(s[start]) != tolower(s[end]))
                return false;
            start ++;
            end --;
        }
        return true;
    }
};