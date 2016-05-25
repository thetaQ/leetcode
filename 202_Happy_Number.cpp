#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    
    int getNext(int n)
    {
        int next_val = 0;
        int tmp;
        while(n > 0)
        {
            tmp = n % 10;
            next_val += tmp * tmp;
            n /= 10;
        }
        return next_val;
    }

    bool isHappy(int n) 
    {
        set<int> cycle;
        while(n != 1)
        {
            set<int>::iterator it = cycle.find(n);
            if(it != cycle.end())
            {
                //find, return false;
                return false;
            }
            else
            {
                cycle.insert(n);
                n = getNext(n);
            }
        }
        return true;
    }
};


int main(void)
{
    Solution solution;
    cout << solution.isHappy(19) << endl;
    return 0;
}