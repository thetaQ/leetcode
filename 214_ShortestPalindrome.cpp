#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    //KMP next array
    void make_next(string s, int *next)
    {
        int q, k;
        int size = s.size();
        next[0] = 0;
        for(q = 1, k = 0; q < size; ++q)
        {
            while(k > 0 && s[q] != s[k])
                k = next[k - 1];
            if(s[q] == s[k])
                k++;
            next[q] = k;
        }
    }
    
    string shortestPalindrome(string s)
    {
        if(s.empty())
            return s;
        string original_str = s;
        reverse(s.begin(), s.end());
        
        string pattern = original_str + "+" + s;
        int size = pattern.size();
        int next[size];
        
        make_next(pattern, next);

        return s.substr(0, original_str.size() - next[size-1])+original_str;
    }
};