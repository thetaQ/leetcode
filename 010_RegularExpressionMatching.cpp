#include <iostream>
#include <string>
using namespace std;

bool isMatch(char *str, char *pattern)
{
    if(*pattern == '\0')
        return *str == '\0';
    
    if(*(pattern + 1) == '*')
    {
        while(*str != '\0' && (*pattern == '.' || *pattern == *str))
        {
            if(isMatch(str, pattern + 2))
                return true;
            str ++;
        }
        return isMatch(str, pattern + 2);
    }
    else
    {
        if(*str != '\0' && (*pattern == '.' || *pattern == *str))
        {
            return isMatch(str + 1, pattern + 1);
        }
        else
            return false;
    }
}