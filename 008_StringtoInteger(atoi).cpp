#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string str)
    {
        int index = 0;
        int sign = 1;
        long long number = 0;

        //step 1: skip spaces
        while(str[index] == ' ')
        {
            index ++;
        }

        //step 2: sign
        if(str[index] == '+')
        {
            sign = 1;
            index ++;
        }
        else if(str[index] == '-')
        {
            sign = -1;
            index ++;
        }

        //step 3: calculate number
        while(index <= str.size()-1)
        {
            if(str[index] < '0' || str[index] > '9')
                break;
            int digit = str[index] - '0';
            number = number * 10 + digit;
            if(sign*number >= INT_MAX || sign*number <= INT_MIN)
            {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            index ++;
        }
        return number * sign;
    }
};