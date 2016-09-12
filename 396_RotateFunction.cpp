#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    //方法一：暴力，超时
    int maxRotateFunction(vector<int>& A) {
        if(A.size() == 0)
            return 0;
        int max_sum = INT_MIN;
        for(int i = 0; i < A.size(); i++)
        {
            int sum = 0;
            for(int j = 0; j < A.size(); j++)
            {
                sum += j * A[(j-i+A.size())%A.size()];
            }
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }

    //方法二
    int maxRotateFunction_2(vector<int>& A) {
        if(A.size() == 0)
            return 0;
        int sum = 0;
        int tmp = 0;
        for(int i = 0; i < A.size(); i++)
        {
            sum += i * A[i];
            tmp += A[i];
        }
        int max_sum = sum;
        for(int i = A.size() - 1; i >= 1; i--)
        {
            sum = sum + tmp - A.size() * A[i];
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }
};