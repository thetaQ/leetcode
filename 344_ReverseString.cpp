#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseString(string s) 
    {
        auto start = s.begin(), end = s.end() - 1;
        while(start < end)
        {
            //swap
            auto tmp = *start;
            *start = *end;
            *end = tmp;

            start ++;
            end --;
        }
        return s; 
    }
};


int main(void)
{
    Solution solution; 
    cout << solution.reverseString("hello") << endl;
    return 0;
}
