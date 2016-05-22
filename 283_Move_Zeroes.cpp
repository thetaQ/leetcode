#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        int zero_count = 0; 
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                zero_count ++;
            }
            else if(zero_count > 0)
            {
                nums[i-zero_count] = nums[i];
                nums[i] = 0;
            }
        }
    }

};

int main()
{

    Solution solution;
    vector<int> nums = {0, 1, 0, 3, 12};
    solution.moveZeroes(nums); 
    
    for(auto n: nums)
    {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}
