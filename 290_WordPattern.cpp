#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void getwords(vector<string>& words, string str)
    {
        int size = str.size();
        int start = 0, i = 0;
        int word_index = 0;
        for(i = 0; i < size; )
        {
            while(i < size && str[i] == ' ')
                i++;
            start = i;
            while(i < size && str[i] != ' ')
                i++;
            string word = str.substr(start, i-start);
            words.push_back(word);
            cout << word << endl;
        }
        return;
    }

    bool wordPattern(string pattern, string str) 
    {
        unordered_map<string, char> stop;
        unordered_map<char, string> ptos;
        vector<string> words;

        getwords(words, str);
        if(words.size() != pattern.size())
            return false;
        int size = words.size();
        for(int i = 0; i < size; ++i)
        {
            string word = words[i];
            char c = pattern[i];
            if(stop.find(word) == stop.end() && ptos.find(c) == ptos.end())
            {
                //do not exist both
                stop[word] = c;
                ptos[c] = word;
            }
            else if(stop.find(word) != stop.end() && ptos.find(c) != ptos.end())
            {
                //both find
                if(stop[word] != c || ptos[c].compare(word) != 0)
                    return false;
            }
            else
            {
                //find in only one
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution solution;
    string pattern = "abba";
    string str = "dog cat cat fish";
    cout << solution.wordPattern(pattern, str) << endl;
}