#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;
        int i = 0;
        for(i = 0; i < nums.size() && i <= reach; i++)
        {
            reach = max(reach, nums[i] + i);
        }
        return i == nums.size();
    }
};