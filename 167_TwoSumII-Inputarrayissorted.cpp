#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        vector<int> result(2);
        int start = 0, end = numbers.size() - 1;
        while(start < end)
        {
            int sum = numbers[start] + numbers[end];
            if(sum == target)
            {
                result[0] = start + 1;
                result[1] = end + 1;
                break;
            }
            else if(sum < target)
            {
                start ++;
            }
            else
            {
                end --;
            }
        }
        return result;
    }
};