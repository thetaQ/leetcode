#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s)
    {
        int size = s.size();
        int end = size - 1;
        for(int i = size - 1; i >= 0; )
        {
            while(i >= 0 && s[i] == ' ')
                i--;
            end = i;
            while(i >= 0 && s[i] != ' ')
                i--;
            return end - i;
        }
        return 0;
    }
};