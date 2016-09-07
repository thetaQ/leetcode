#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

string decodeString(string s)
{
    stack<int> digit_stack;
    stack<string> str_stack;
    string res = "";
    int i = 0;
    while(i < s.size())
    {
        if(isdigit(s[i]))
        {
            int digit = 0;
            while(isdigit(s[i]))
            {
                digit = digit * 10 + s[i] - '0';
                i ++;
            }
            digit_stack.push(digit);
        }
        else if(s[i] == '[')
        {
            str_stack.push(res);
            res = "";
            i ++;
        }
        else if(s[i] == ']')
        {
            string tmp = str_stack.top();
            str_stack.pop();
            int repeat_time = digit_stack.top();
            digit_stack.pop();
            for(int k = 0; k < repeat_time; k++)
            {
                tmp += res;
            }
            res = tmp;
            i ++;
        }
        else
        {
            res.push_back(s[i++]);
        }
    }
    return res;
}

int main()
{
    string s = "3[a]2[bc]";
    cout << decodeString(s) << endl;
    return 0;
}