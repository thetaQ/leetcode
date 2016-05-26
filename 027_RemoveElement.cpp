#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    //参考题目283 move zeros
    int removeElement(vector<int>& nums, int val)
    {
        int val_cnt = 0;
        int size = nums.size();
        for(int i = 0; i < size; i++)
        {
            if(nums[i] == val)
            {
                val_cnt ++;
            }
            else if(val_cnt > 0)
            {
                nums[i-val_cnt] = nums[i];
                nums[i] = val;
            }
        }
        return size - val_cnt;
    }
};

int main(void)
{
    Solution solution;
    vector<int> nums = {3, 2, 2, 3};
    cout << solution.removeElement(nums, 3);
    return 0;
}