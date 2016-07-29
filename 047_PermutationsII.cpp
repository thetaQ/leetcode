#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int> > result;
        vector<int> solution;
        vector<bool> visited(nums.size(), false);
        permuteUnique(result, nums, visited, solution, 0);
        return result;
    }
private:
    void permuteUnique(vector<vector<int> >& result, vector<int>& nums, vector<bool>& visited, vector<int>& solution, int index)
    {
        if(index == nums.size())
        {
            result.push_back(solution);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(visited[i])
                continue;
            if(i > 0 && nums[i] == nums[i-1] && !visited[i-1])
                continue;
            solution.push_back(nums[i]);
            visited[i] = true;
            permuteUnique(result, nums, visited, solution, index + 1);
            solution.pop_back();
            visited[i] = false;
        }
    }
};