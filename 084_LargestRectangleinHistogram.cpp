#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        int size = heights.size();
        if(size == 0)
            return 0;
        vector<int> new_heights(heights);
        new_heights.push_back(0);

        int i = 0;
        stack<int> s;
        int max_area = 0;
        while(i < size + 1)
        {
            if(s.empty() || new_heights[i] >= new_heights[s.top()])
            {
                s.push(i++);
            }
            else
            {
                int index = s.top();
                s.pop();
                max_area = max(max_area, new_heights[index] * (s.empty() ? i : i - s.top() - 1));
            }
        }
        return max_area;
    }
};