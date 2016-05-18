#include <iostream>

using namespace std;

class Solution {
public:
    //solution one: loop
    int addDigits_1(int num) 
    {
        while(num/10 != 0) 
        {
            num = add_one_time(num);
        }
        return num;
    }
    
    //Solution: 每9个数一个循环
    int addDigits(int num) 
    {
        return (num-1)%9 + 1;
    }


private:
    int add_one_time(int num) 
    {
        int sum = 0;
        while(num != 0)
        {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};



int main(void)
{
    Solution solution;
    cout << solution.addDigits(38) << endl;
    cout << solution.addDigits(9) << endl;
    cout << solution.addDigits(0) << endl;
    return 0;
}
