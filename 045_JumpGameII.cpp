#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int>& A) {
        // wirte your code here
        if(A.size() <= 1)
            return 0;
        int begin = 0, end = A[0];
        int max_jump = 0, count = 1;
        while(end < A.size()-1)
        {
            count ++;
            int index = begin;
            for(; index <= end; index ++)
            {
                max_jump = max(max_jump, A[index] + index);
            }
            begin = index;
            end = max_jump;
        }
        return count;
    }
};