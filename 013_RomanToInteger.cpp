#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s)
    {
        int size = s.size();
        int rti[100] = {0};    
        int result = 0;
        for(int i = 0; i < size; i++)
        {
            switch(s[i]) 
            {
            case 'I': rti[i] = 1;    break;
            case 'V': rti[i] = 5;    break;
            case 'X': rti[i] = 10;   break;
            case 'L': rti[i] = 50;   break;
            case 'C': rti[i] = 100;  break;
            case 'D': rti[i] = 500;  break;
            case 'M': rti[i] = 1000; break;
            }
        }
        
        for(int i = 0; i < size; i++)
        {
            result += (rti[i] >= rti[i+1]) ? rti[i] : (-1) * rti[i];
        }
        return result;
    }
};


int main(void)
{
    Solution solution;
    string s = "XIX";
    cout << solution.romanToInt(s) << endl;
    return 0;
}
