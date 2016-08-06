#include <iostream>
#include <string>
#include <deque>
using namespace std;

class Solution {
public:
    int calculate(string s)
    {
        size_t size = s.size();
        deque<int> q;
        char prev_opt ='+';
        for(size_t i = 0; i < size; ++i)
        {
            if(s[i] == ' ')
                continue;
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            {
                prev_opt = s[i];
            }
            else if(isdigit(s[i]))
            {
                //calculate digit
                int digit = 0;
                while(i < size && isdigit(s[i]))
                {
                    digit = digit * 10 + s[i] - '0';
                    ++i;
                }
                i --;
                if(prev_opt == '*')
                {
                    int last_digit = q.back();
                    q.pop_back();
                    q.push_back(last_digit * digit);
                }
                else if(prev_opt == '/')
                {
                    int last_digit = q.back();
                    q.pop_back();
                    q.push_back(last_digit / digit);
                }
                else if(prev_opt == '-')
                {
                    q.push_back(-1 * digit);
                }
                else
                {
                    q.push_back(digit);
                }
            }
        }
        
        int res = 0;
        while(!q.empty())
        {
            res += q.front();
            q.pop_front();
        }
        return res;
    }
};

int main(void)
{
    Solution solution;
    string s = " 3/2 ";
    cout << solution.calculate(s) << endl;
    return 0;
}