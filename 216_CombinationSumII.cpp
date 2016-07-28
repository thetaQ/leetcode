#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n)
    {
        vector<vector<int> >result;
        vector<int> solution;
        combinationCore(result, k, solution, n, 1);
        return result;
    }
private:
    void combinationCore(vector<vector<int> >& result, int k, vector<int>& solution, int target, int index)
    {
        if(k == 0 && target == 0)
        {
            result.push_back(solution);
            return;
        }
        else if(k == 0 || target == 0)
            return;
        
        for(int i = index; i <= 9 && target >= i; i++)
        {
            solution.push_back(i);
            combinationCore(result, k - 1, solution, target - i, i + 1);
            solution.pop_back();
        }
        return;
    }
};