#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        int carry = 0;
        int size = digits.size();
        for(int i = size - 1; i >= 0; i--)
        {
            if(i == size - 1)
                digits[i] += 1;
            int tmp = digits[i] + carry;
            digits[i] = tmp % 10;
            carry = tmp / 10;
        }
        if(carry > 0)
            digits.insert(digits.begin(), carry);
        return digits;
    }
};

int main(void)
{
    Solution solution;
    vector<int> digits = {1, 2, 3};
    vector<int> result = solution.plusOne(digits);
    return 0;
}