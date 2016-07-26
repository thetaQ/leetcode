#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> >& matrix)
    {
        int n = matrix.size();
        for(int layer = 0; layer < n / 2; layer++)
        {
            //左上角坐标(layer, layer)
            int start = layer;
            int end = n - layer - 1;
            for(int i = start; i < end; i++)
            {
                int offset = i - start;
                int tmp = matrix[start][i];

                matrix[start][i] = matrix[end - offset][start];
                matrix[end - offset][start] = matrix[end][end - offset];
                matrix[end][end - offset] = matrix[i][end];
                matrix[i][end] = tmp;
            } 
        }
    }
};