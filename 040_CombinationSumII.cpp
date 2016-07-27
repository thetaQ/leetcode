#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target)
    {
        vector<vector<int> > result;
        vector<int> solution;
        sort(candidates.begin(), candidates.end());
        combination_core(result, candidates, target, solution, 0);
        return result;
    }
private:
    void combination_core(vector<vector<int> >& result, vector<int>& candidates, int target, vector<int>& solution, int index)
    {
        if(target == 0)
        {
            result.push_back(solution);
            return;
        }

        for(int i = index; i < candidates.size() && target >= candidates[i]; i++)
        {
            if(i != index && candidates[i] == candidates[i-1])
                continue;
            solution.push_back(candidates[i]);
            combination_core(result, candidates, target - candidates[i], solution, i + 1);
            solution.pop_back();
        }
        return;
    }
};