#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isScrambleCore(unordered_map<string, bool>& cache, string s1, string s2)
    {
        int size = s1.size();
        int res = false;
        if(size == 0)
            return true;
        else if(size == 1)
            return s1 == s2;
        else
        {
            if(cache.find(s1+s2) != cache.end())
            {
                return cache[s1+s2];
            }
            if(s1 == s2)
                return true;
            else
            {
                for(int i = 1; i < size && !res; i++)
                {
                    res = res || (isScrambleCore(cache, s1.substr(0, i), s2.substr(0, i)) && isScrambleCore(cache, s1.substr(i, size-i), s2.substr(i, size-i)));
                    res = res || (isScrambleCore(cache, s1.substr(0, i), s2.substr(size-i, i)) && isScrambleCore(cache, s1.substr(i, size-i), s2.substr(0, size-i)));
                }
                cache[s1+s2] = res;
                return res;
            }
        }
    }

    bool isScramble(string s1, string s2)
    {
        if(s1.size() != s2.size())
            return false;
        unordered_map<string, bool> cache;
        return isScrambleCore(cache, s1, s2);
    }
};