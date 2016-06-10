#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool match(char left, char right)
    {
        if(left == '{' && right == '}')
            return true;
        if(left == '(' && right == ')')
            return true;
        if(left == '[' && right == ']')
            return true;
        return false;
    }

    bool isValid(string s)
    {
        stack<char> pattern;
        for(char c: s)
        {
            if(c == '[' || c == '(' || c == '{')
                pattern.push(c);
            else if(c == ']' || c == ')' || c == '}')
            {
                if(pattern.empty())
                    return false;
                char top = pattern.top();
                if(!match(top, c))
                    return false;
                else
                    pattern.pop();
            }
            else 
                return false;
        }
        return pattern.empty();
    }
};