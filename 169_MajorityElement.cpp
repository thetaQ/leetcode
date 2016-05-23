#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    /************************************************************/
    /* solution one:                                            */
    /* We can change this problem to another problem: Find the  */
    /* kth-min number, using thinking of quick-sort             */
    /************************************************************/
    int partition(vector<int>& nums, int lo, int hi)
    {
        int i = lo, j = hi + 1;
        int flag = nums[lo];
        while(true)
        {
            while(nums[++i] < flag) if(i == hi) break; 
            while(flag < nums[--j]) if(j == lo) break;
            if(i >= j)
                break;
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
        int temp = nums[lo];
        nums[lo] = nums[j];
        nums[j] = temp;
        return j;
    }

    int find(vector<int>& nums, int lo, int hi)
    {
        int k = nums.size()/2;
        if(hi <= lo)
            return nums[lo];
        int j = partition(nums, lo, hi);
        if(j == k)
        {
            return nums[k]; 
        }
        else if(j < k)
        {
            return find(nums, j + 1, hi);
        }
        else 
        {
            return find(nums, lo, j - 1); 
        }
    }

    //find the kth-min number
    int majorityElement(vector<int>& nums) 
    {
        return find(nums, 0, nums.size() - 1); 
    }

    /*************************************************************/
    /* solution two:                                             */
    /* We can sort the array first, then the middle of the array */
    /* is the number we want                                     */
    /*************************************************************/
    static bool comp(const int& a, const int& b)
    {
        return a < b;
    }

    int majorityElement_2(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end(), comp);
        return nums[nums.size()/2];
    }


    /*************************************************************/
    /* solution three:                                           */
    /* Majority Vote Algorithm                                   */
    /*************************************************************/
    int majorityElement_3(vector<int>& nums) 
    {
        int count = 0, candidate = nums[0];
        for(int num: nums)
        {
            if(count == 0)
            {
                candidate = num;
            }

            if(candidate == num)
            {
                count ++;
            }
            else
            {
                count --;
            }
        }
        //since "the majority element always exist in the array", 
        //there is no need to verify candidate
        return candidate;
    }
};

int main(void)
{
    Solution solution;
    vector<int> nums = {4, 5, 4};
    cout << solution.majorityElement_2(nums) << endl; 
    return 0;
}
