#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums)
    {
        vector<vector<int> > result;
        vector<int> solution;
        vector<bool> contained(nums.size(), false);
        permuteCore(result, nums, contained, solution, 0);
        return result;
    }
private:
    void permuteCore(vector<vector<int> >& result, vector<int>& nums, vector<bool>& contained, vector<int>& solution, int index)
    {
        if(index == nums.size())
        {
            result.push_back(solution);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(contained[i])
                continue;
            solution.push_back(nums[i]);
            contained[i] = true;
            permuteCore(result, nums, contained, solution, index + 1);
            solution.pop_back();
            contained[i] = false;
        }
        return;
    }
};