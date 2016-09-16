#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        if(nums.size() == 0)
            return 0;
        int next_to_read = 1, next_to_write = 1;
        int cnt = 1;
        while(next_to_read < nums.size())
        {
            if(nums[next_to_read] == nums[next_to_read - 1])
            {
                cnt ++;
                if(cnt > 2)
                {
                    next_to_read ++;
                    continue;
                }
                else
                    nums[next_to_write ++] = nums[next_to_read ++];
            }
            else
            {
                cnt = 1;
                nums[next_to_write ++] = nums[next_to_read ++];
            }
        }
        return next_to_write;
    }

    //leetcode discuss
    int removeDuplicates_2(vector<int>& nums) {
    int i = 0;
    for (int n : nums)
        if (i < 2 || n > nums[i-2])
            nums[i++] = n;
    return i;
}
};