#include <iostream>
using namespace std;

class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        if(s == NULL || p == NULL)
            return false;
        const char *pp = NULL, *ss = NULL;
        while(*s != '\0')
        {
            if(*s == *p || *p == '?')
            {
                s++;
                p++;
                continue;
            }
            
            if(*p == '*')
            {
                pp = p ++;
                ss = s;
                continue;
            }
            
            //不匹配时
            if(pp != NULL)
            {
                p = pp + 1;
                s = ss + 1;
                ss ++;
                continue;
            }
            return false;
        }
        
        while(*p == '*')
            p++;
        return *p == '\0';
    }
};