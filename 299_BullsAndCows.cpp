#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess)
    {
        unordered_map<char, int> mm;
        int bulls = 0, cows = 0;
        for(int i = 0; i < secret.size(); ++i)
        {
            if(i < guess.size() && secret[i] == guess[i])
            {
                bulls ++;
                continue;
            }
            mm[secret[i]] ++;
        }
        
        for(int i = 0; i < secret.size(); ++i)
        {
            if(i < guess.size() && guess[i] != secret[i] && mm[guess[i]] > 0)
            {
                mm[guess[i]] --;
                cows ++;
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};