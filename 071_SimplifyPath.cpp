#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string simplifyPath(string path)
    {
        string res = "";
        if(path.size() == 0)
            return res;
        path = "/" + path + "/";
        int cur = 0;
        int size = path.size();
        while(cur < size)
        {
            if(path[cur] == '/')
            {
                res.push_back('/');
                while(cur < size && path[cur] == '/')
                    cur ++;
            }
            else if (cur+1 < size && path[cur-1] != '.' && path[cur] == '.' && path[cur+1] == '/')
            {
                cur ++;
                while(cur < size && path[cur] == '/')
                    cur ++;
            }
            else if(cur+2 < size && path[cur-1] != '.' && path[cur] == '.' && path[cur+1] == '.' && path[cur+2] == '/')
            {
                if(res.size() > 1)
                    res.pop_back();
                while(res.size() > 0 && res[res.size()-1] != '/')
                    res.pop_back();
                cur += 2;
                while(cur < size && path[cur] == '/')
                    cur ++;
            }
            else
            {
                res.push_back(path[cur++]);
            }
        }
        if(res.size() > 1)
            res.pop_back();
        return res;
    }


};