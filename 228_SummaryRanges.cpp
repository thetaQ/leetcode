#include <iostream>
#include <vector>
using namespace std;

vector<string> summaryRanges(vector<int>& nums)
{
    vector<string> res;
    if(nums.size() == 0)
        return res;
    
    int begin = 0, end = 0;
    while(begin < nums.size())
    {
        int index = begin + 1;
        while(index < nums.size() && nums[index] == nums[index - 1] + 1)
            index ++;
        end = index - 1;
        string str;
        if(begin == end)
        {
            str = to_string(nums[begin]);
        }
        else
        {
            str = to_string(nums[begin]) + "->" + to_string(nums[end]);
        }
        res.push_back(str);
        begin = index;
    }
    return res;
}
int main()
{
    vector<int> nums = {0, 1};
    vector<string> res = summaryRanges(nums);
    for(auto str: res)
    {
        cout << str << endl;
    }
}


