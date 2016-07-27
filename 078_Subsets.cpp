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

    void combine_2(vector<int>& nums, vector<int>&path, int index)
    {
        if(index <= nums.size())
        {
            vector<int> tmp(path);
            result.push_back(tmp);
        }
        
        for(int i = index; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            combine(nums, path, i + 1);
            path.pop_back();
        }
        return;
    }

    vector<vector<int> > subsets(vector<int>& nums)
    {
        sort(nums.begin(), nums.end(), mcmp);
        vector<int> path;
        combine(nums, path, 0);
        return result;
    }


    //迭代法
    vector<int> convertIntToSet(vector<int>& nums, int x)
    {
        vector<int> set;
        int index = 0;
        for(int k = x; k > 0; k >>= 1)
        {
            if((k & 1) == 1)
                set.push_back(nums[index]);
            index ++;
        }
        return set;
    }

    vector<vector<int> > subsets_iteratively(vector<int>& nums)
    {
        sort(nums.begin(), nums.end(), mcmp);
        vector<vector<int> > result;
        int max = 1 << nums.size();
        for(int i = 0; i < max; i++)
        {
            vector<int> subset = convertIntToSet(nums, i);
            result.push_back(subset);
        }
        return result;
    }
};