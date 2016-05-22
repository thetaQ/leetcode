#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> alphabet;
        for(char c: s)
        {
            unordered_map<char, int>::iterator it = alphabet.find(c);
            if(it == alphabet.end())
            {
                alphabet[c] = 1;
            }
            else
            {
                alphabet[c] ++;
            }
        }

        for(char c: t)
        {
            unordered_map<char, int>::iterator it = alphabet.find(c);
            if(it == alphabet.end())
            {
               return false; 
            }
            else
            {
                alphabet[c] --;
                if(alphabet[c] == 0)
                {
                    alphabet.erase(c);
                }
            }
        }
        if(alphabet.empty())
            return true;
        return false;
    }
};



int main(void)
{
    Solution solution;
    string s1 = "anagram";
    string s2 = "nagaram";
    cout << solution.isAnagram(s1, s2) << endl;
    return 0;
}
