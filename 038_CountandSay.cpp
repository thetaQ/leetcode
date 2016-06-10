#include <iostream>
#include <string>
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