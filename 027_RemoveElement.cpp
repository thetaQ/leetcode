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
    
    //思路2， 如果当前值等于val，则将末尾的一个数移动过来
    int removeElement_2(vector<int>& nums, int val)
    {
        int i = 0, j = nums.size() - 1;
        while(i <= j)
        {
            if(nums[i] == val)
            {
                nums[i] = nums[j--];
                continue;
            }
            i++;
        }
        return i;
    }
    
};

int main(void)
{
    Solution solution;
    vector<int> nums = {3, 2, 2, 3};
    cout << solution.removeElement(nums, 3);
    return 0;
}