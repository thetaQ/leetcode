#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int> > result;
        vector<int> solution;
        sort(candidates.begin(), candidates.end());
        combinecore(result, candidates, target, solution, 0);
        return result;
    }
private:
    void combinecore(vector<vector<int> >& result, vector<int>& candidates, int target, vector<int>& solution, int index)
    {
        if(target == 0)
        {
            result.push_back(solution);
        }

        for(int i = index; i < candidates.size() && target >= candidates[i]; i++)
        {
            solution.push_back(candidates[i]);
            combinecore(result, candidates, target - candidates[i], solution, i);
            solution.pop_back();
        }
    }
};