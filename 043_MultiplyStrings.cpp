#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string add(string num1, string num2)
    {
        int size1 = num1.size(), size2 = num2.size();
        if(size1 == 0) return num2;
        if(size2 == 0) return num1;
        int index1 = size1 - 1, index2 = size2 - 1;
        int carry = 0;
        string res;
        while(index1 >= 0 && index2 >= 0)
        {
            int sum = num1[index1--] - '0' + num2[index2--] - '0' + carry;
            carry = sum / 10;
            res.push_back(sum % 10 + '0');
        }
        while(index1 >= 0)
        {
            int sum = num1[index1--] - '0' + carry;
            carry = sum / 10;
            res.push_back(sum % 10 + '0');
        }
        while(index2 >= 0)
        {
            int sum = num2[index2--] - '0' + carry;
            carry = sum / 10;
            res.push_back(sum % 10 + '0');
        }
        if(carry > 0)
        {
            res.push_back(carry + '0');
        }
        reverse(res.begin(), res.end());
        return res;
    }

    string multiply_single(string num, char c)
    {
        string res;
        int size = num.size();
        int carry = 0;
        for(int i = size-1; i >= 0; --i)
        {
            int multi = (num[i] - '0') * ( c- '0') + carry;
            carry = multi / 10;
            res.push_back(multi % 10 + '0');
        }
        if(carry > 0)
        {
            res.push_back(carry + '0');
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    string multiply(string num1, string num2)
    {
        int size1 = num1.size(), size2 = num2.size();
        if(size1 == 0 || size2 == 0)
            return "";
        string res = "";
        for(int i = size2-1; i >= 0; --i)
        {
            string tmp_str = multiply_single(num1, num2[i]);
            for(int j = 0; j < size2-1-i; j++)
            {
                tmp_str.push_back('0');
            }
            res = add(res, tmp_str);
        }
        //clear zero
        int i = 0;
        for(i = 0; i < res.size()-1; i++)
        {
            if(res[i] != '0')
                break;
        }
        return res.substr(i);
    }
};