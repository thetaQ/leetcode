#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
    {
        set<int> ss;      
        for(int n: nums)
        {
            set<int>::iterator it = ss.find(n);
            if(it == ss.end())
            {
                ss.insert(n);
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};


int main(void)
{
    Solution solution;
    vector<int> nums = {1, 2, 3, 3, 4, 5};
    cout << solution.containsDuplicate(nums) << endl;
    return 0;
}
