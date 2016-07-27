#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > result;
    static bool mcmp(const int& a, const int& b)
    {
        return a < b;
    }
    void combine(vector<int>& nums, vector<int>path, int index)
    {
        if(index == nums.size())
        {
            result.push_back(path);
            return;
        }
        combine(nums, path, index + 1); //不选

        path.push_back(nums[index]);   //选
        combine(nums, path, index + 1);
        return;
    }

    vector<vector<int> > subsets(vector<int>& nums)
    {
        sort(nums.begin(), nums.end(), mcmp);
        vector<int> path;
        combine(nums, path, 0);
        return result;
    }
};