#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b)
    {
        string ret;
        int length_a = a.size()-1;
        int length_b = b.size()-1;
        char carry = '0';
        /**
        * a+b+carry如何返回？
        * sum = a+b+carry;
        * ret = sum%进制
        * carry = sum/进制
        */
        while(length_a >= 0 && length_b >= 0)
        {
            int sum = (a[length_a--] - '0') + (b[length_b--] - '0') + (carry - '0');
            carry = sum / 2 + '0';
            ret.push_back(sum%2 + '0');
        }
        while(length_a >= 0)
        {
            int sum = (a[length_a--] - '0') + (carry - '0');
            carry = sum / 2 + '0';
            ret.push_back(sum%2 + '0');
        }
        while(length_b >= 0)
        {
            int sum = (b[length_b--] - '0') + (carry - '0');
            carry = sum / 2 + '0';
            ret.push_back(sum%2 + '0');
        }
        if(carry == '1')
        {
            ret.push_back('1');
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
