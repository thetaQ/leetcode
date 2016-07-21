#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height)
    {
        int second_height = -1;
        int left = 0, right = height.size() - 1;
        int area = 0;
        while(left < right)
        {
            if(height[left] > height[right])
            {
                second_height = max(second_height, height[right]);
                area += second_height - height[right];
                right --;
            }
            else
            {
                second_height = max(second_height, height[left]);
                area += second_height - height[left];
                left ++;
            }
        }
        return area;
    }
};