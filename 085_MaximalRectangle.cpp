#include <iostream>
#include <vector>
#include <stack>
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

    int maximalRectangle(vector<vector<char>>& matrix)
    {
        int rows = matrix.size();
        if(rows == 0)
            return 0;
        int cols = matrix[0].size();
        if(cols == 0)
            return 0;
        vector<vector<int>> new_matrix(rows, vector<int>(cols, 0));    
        
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                new_matrix[i][j] = matrix[i][j] - '0';
                if(i > 0 && matrix[i][j] > '0')
                    new_matrix[i][j] += new_matrix[i-1][j];
            }
        }
        
        int max_area = 0;
        for(int i = 0; i < rows; i++)
        {
            max_area = max(max_area, largestRectangleArea(new_matrix[i]));
        }
        return max_area;
    }
};