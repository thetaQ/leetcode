#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void combineCore(vector<vector<int> > &result, int n, int k, vector<int>&solution, int index)
    {
        if(k == 0)
        {
            result.push_back(solution);
            return;
        }
        for(int i = index; i <= n; i++)
        {
            solution.push_back(i);
            combineCore(result, n, k - 1, solution, i + 1);
            solution.pop_back();
        }
        return;
    }
    
    vector<vector<int> > combine(int n, int k)
    {
        vector<vector<int> > result;
        vector<int> solution;
        combineCore(result, n, k, solution, 1);
        return result;
    }
};