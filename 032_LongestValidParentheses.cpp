#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:

    //方法一：用栈
    int longestValidParentheses(string s)
    {
        int result = 0;
        stack<int> stack;
        stack.push(-1);
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ')' && !stack.empty() && stack.top() >= 0 && s[stack.top()] == '(')
            {
                stack.pop();
                result = max(result, i - stack.top());
            }
            else
            {
                stack.push(i);
            }
        }
        return result;
    }

    //方法二： DP
    int longestValidParentheses_2(string s)
    {
        if(s.size() <= 1)
            return 0;
        //length[i]表示以i结尾的子串，最大合法的长度            
        vector<int> length(s.size(), 0);
        int cur_max = 0;
        for(int i = 1; i < s.size(); i++)
        {
            if(s[i] == ')')
            {
                if(s[i-1] == '(')
                {
                    length[i] = (i - 2 >= 0)?(length[i-2] + 2) : 2;
                    cur_max = max(cur_max, length[i]);
                }
                else
                {
                    if(i - length[i-1] - 1 >= 0 && s[i-length[i-1]-1] == '(')
                    {
                        length[i] = length[i-1] + 2 + ((i - length[i-1] - 2 >= 0) ? length[i - length[i-1] - 2] : 0);
                        cur_max = max(cur_max, length[i]);
                    }
                }
            }
        }
        return cur_max;
    }
};