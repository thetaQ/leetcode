#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>

using namespace std;

bool isvalid(string s)
{
    if(s.empty())
        return false;
    int digit = 0;
    if(s.size() > 1 && s[0] == '0')
        return false;
    for(int i = 0; i < s.size(); i++)
    {
        digit = digit * 10 + s[i] - '0';
        if(digit >= 256)
            return false;
    }
    return true;
}

void restore(vector<string>& result, string s, string one_solution, int curr_index, int point_cnt)
{
    if(point_cnt == 3)
    {
        if(isvalid(s.substr(curr_index)))
        {
            one_solution += s.substr(curr_index);
            result.push_back(one_solution);
        }
        return;
    }
    
    for(int i = curr_index; i < s.size(); i++)
    {
        if(isvalid(s.substr(curr_index, i-curr_index+1)))
            restore(result, s, one_solution + s.substr(curr_index, i-curr_index+1) + ".", i+1, point_cnt+1);
        else
            break;
    }
}

vector<string> restoreIpAddresses(string s)
{
    vector<string> result;
    string one_solution = "";
    restore(result, s, one_solution, 0, 0);
    return result;
}

int main()
{
    vector<string> result;
    string s = "010010";
    result = restoreIpAddresses(s);
    for(string str: result)
    {
        cout << str << endl;
    }
    return  0;
}