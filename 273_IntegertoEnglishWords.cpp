#include <iostream>
#include <string>
using namespace std;

string digits[] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
string teens[] = {"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
string tens[] = {"Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
string bigs[] = {"", "Thousand", "Million", "Billion"};

class Solution {
public:
    string numberToWords(int num)
    {
        int count = 0;
        string str = "";
        if(num == 0)
            return "Zero";
        while(num > 0)
        {
            if(num % 1000 != 0)
            {
                str = numTo100(num % 1000) + bigs[count] + " " + str;
            }
            num /= 1000;
            count ++;
        }

        //注意！去除末尾的0！
        str.erase(str.find_last_not_of(" ") + 1);
        return str;
    }
private:
    string numTo100(int num)
    {
        string str = "";
        //百位
        if(num >= 100)
        {
            str += digits[num/100-1] + " Hundred ";
            num %= 100;
        }
        //十位
        if(num >= 11 && num <= 19)
        {
            return str + teens[num - 11] + " ";
        }
        else if(num == 10 || num >= 20)
        {
            str += tens[num/10 - 1] + " ";
            num %= 10;
        }

        if(num >= 1 && num <= 9)
        {
            str += digits[num - 1] + " ";
        }
        return str;
    }
};