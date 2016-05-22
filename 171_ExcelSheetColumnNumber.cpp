#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(string s)
    {
        int result = 0;
        for(auto c: s)
        {
            result = result * 26 + (c - 'A' + 1);
        }
        return result;
    }
};

int main(void)
{
    Solution solution;
    std::string s = "AB";
    std::cout << solution.titleToNumber(s) << std::endl;
    return 0;
}
