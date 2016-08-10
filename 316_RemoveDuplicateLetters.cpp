#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s)
    {
        vector<int> counter(26, 0);
        vector<bool> visited(26, false);
        stack<char> chars;
        for(char c: s)
        {
            counter[c-'a'] ++;
        }
        for(int i = 0; i < s.size(); i++)
        {
            counter[s[i]-'a']--;
            if(visited[s[i]-'a'])
                continue;
            while(!chars.empty() && s[i] < chars.top() && counter[chars.top()-'a'] != 0)  //后面还有
            {
                visited[chars.top()-'a'] = false;
                chars.pop();
            }
            chars.push(s[i]);
            visited[s[i]-'a'] = true;
        }
        
        string res;
        while(!chars.empty())
        {
            res.push_back(chars.top());
            chars.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }

};