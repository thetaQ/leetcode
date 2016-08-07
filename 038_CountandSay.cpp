#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    string getNext(string str)
    {
        int size = str.size();
        char cur = str[0];
        int cur_cnt = 0;
        string res;
        for(int i = 0; i < size; i++)
        {
            if(str[i] == cur)
            {
                cur_cnt ++;
            }
            else
            {
                //
                res.push_back(cur_cnt + '0');
                res.push_back(cur);
                //
                cur = str[i];
                cur_cnt = 0;
                i--;
            }
        }
        return res;
    }

    string countAndSay(int n)
    {
        string first = "1";
        n--;
        while(n --)
        {
            first = getNext(first);
        }
        return first;
    }
};


class Solution2 {
public:
    string countAndSay(int n)
    {
        string s = "1";
        for(int i = 0; i < n - 1; ++i)
        {
            s = get_next(s);
        }
        return s;
    }
private:
    string get_next(string s)
    {
        stringstream res;
        int size = s.size();
        int curr_cnt = 1;
        for(int i = 1; i < size; i++)
        {
            if(s[i] == s[i - 1])
                curr_cnt ++;
            else
            {
                res << curr_cnt << s[i-1];
                curr_cnt = 1;
            }
        }
        res << curr_cnt << s[size-1];
        return res.str();
    }
};