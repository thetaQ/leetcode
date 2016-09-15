#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:

    //方法一：循环交换，多个环
    void rotate(vector<int>& nums, int k)
    {
        int size = nums.size();
        if(size == 0)
            return;
        k = k % size;
        
        int start = 0, curr = 0;
        int tmp_num = nums[0];
        int rotate_cnt  = 0;
        while(rotate_cnt < size)
        {
            do
            {
                int next_tmp = nums[(curr + k) % size];
                nums[(curr + k) % size] = tmp_num;
                tmp_num = next_tmp;
                curr = (curr + k) % size;
                rotate_cnt ++;
            }while(curr != start);
            
            start ++;
            curr = start;
            tmp_num = nums[start];
        }
    }


    //方法二： 翻转
    void reverse(vector<int>&nums, int start, int end)
    {
        while(start < end)
        {
            int tmp = nums[start];
            nums[start] = nums[end];
            nums[end] = tmp;
            start ++;
            end --;
        }
    }

    void rotate_2(vector<int>& nums, int k)
    {
        int size = nums.size();
        if(size == 0)
            return;
        k = k % size;
        
        reverse(nums, 0, size - k - 1);
        reverse(nums, size - k, size - 1);
        reverse(nums, 0, size - 1);   
    }

    //方法三：递归的思想
    void rotate_3(int nums[], int n, int k) 
    {
        for (; k = k % n; n -= k, nums += k)
        {
            // Swap the last k elements with the first k elements. 
            // The last k elements will be in the correct positions
            // but we need to rotate the remaining (n - k) elements 
            // to the right by k steps.
            for (int i = 0; i < k; i++)
            {
                swap(nums[i], nums[n - k + i]);
            }
        }
    }
};