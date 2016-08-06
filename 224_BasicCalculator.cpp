#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int calculate(string s)
    {
        size_t size = s.size();
        stack<int> ss;
        int last_sign = 1, result = 0;
        for(size_t i = 0; i < size; i++)
        {
            if(isdigit(s[i]))
            {
                int digit = s[i] - '0';
                while(i + 1 < size && isdigit(s[i+1]))
                {
                    digit = 10 * digit + s[i+1] - '0';
                    i++;
                }
                result += last_sign * digit;
            }
            else if(s[i] == '+')
            {
                last_sign = 1;
            }
            else if(s[i] == '-')
            {
                last_sign = -1;
            }
            else if(s[i] == '(')
            {
                ss.push(result);
                ss.push(last_sign);
                result = 0;
                last_sign = 1;
            }
            else if(s[i] == ')')
            {
                int sign = ss.top();
                ss.pop();
                int tmp_result = ss.top();
                ss.pop();
                result = result * sign + tmp_result;
            }
        }
        return result;
    }
};