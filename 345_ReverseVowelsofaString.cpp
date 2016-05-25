#include <iostream>
#include <string>

using namespace std;

class Solution {
public:

    bool isVowel(char c)
    {
        return (c == 'a' || c == 'A' ||
                c == 'e' || c == 'E' ||
                c == 'i' || c == 'I' ||
                c == 'o' || c == 'O' ||
                c == 'u' || c == 'U');
    }
    
    
    string reverseVowels(string s) 
    {
        string::iterator start = s.begin();
        string::iterator end = s.end() - 1;
        while(start < end)
        {
            while(start < end && !isVowel(*start))
            {
                start ++;
            }
            while(start < end && !isVowel(*end))
            {
                end --;
            }
            
            //swap 
            char tmp = *start;
            *start = *end;
            *end = tmp;
            start ++;
            end --;
        }
        return s;
    }
};


int main()
{
    Solution solution;
    string s = "leetcode";
    cout << solution.reverseVowels(s) << endl;
    return 0;
}