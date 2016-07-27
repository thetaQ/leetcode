#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > result;
    static bool cmp(const int& a, const int& b)
    {
        return a < b;
    }

    void combine(vector<int>&nums, vector<int>&path, int index)
    {
        if(index <= nums.size())
        {
            vector<int> v(path);
            result.push_back(v);
        }

        for(int i = index; i < nums.size(); i++)
        {
            if(i != index && nums[i] == nums[i - 1])
                continue;
            path.push_back(nums[i]);
            combine(nums, path, i + 1);
            path.pop_back();
        }
        return;
    }


    vector<vector<int> > subsetsWithDup(vector<int>& nums)
    {
        vector<int> path;
        sort(nums.begin(), nums.end(), cmp);
        combine(nums, path, 0);
        return result;
    }
};