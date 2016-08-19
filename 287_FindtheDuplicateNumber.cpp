#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    //方法一
    int findDuplicate(vector<int>& nums)
    {
        int size = nums.size();
        for(int i = 0; i < size; i++)
        {
            while(nums[i] != i)
            {
                if(nums[i] == nums[nums[i]])
                    return nums[i];
                int tmp = nums[i];
                nums[i] = nums[tmp];
                nums[tmp] = tmp;
            }
        }
        return -1;//error
    }

    //方法二：
    int findDuplicate_2(vector<int>& nums)
    {
        int result = 0;
        for(int bit = 0; bit < 32; bit++)
        {
            int mask = 1 << bit;
            int a = 0, b = 0;
            for(int i = 0; i < nums.size(); i++)
            {
                if(i > 0 && i & mask)
                    a ++;
                if(nums[i] & mask)
                    b ++;
            }
            if(b > a)
                result |= mask;
        }
        return result;
    }


    /* 方法三：寻找链表环的入口 */
    int findDuplicate_3(vector<int>& nums)
    {
        int slow = 0, fast = 0;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        slow = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }

};