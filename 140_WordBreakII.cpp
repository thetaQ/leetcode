#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
unordered_map<string, vector<string> > table;
public:
    vector<string> wordBreakCore(string s, unordered_set<string>& wordDict)
    {
        vector<string> res;
        if(table.find(s) != table.end())
            return table[s];
        if(wordDict.find(s) != wordDict.end())
        {
            res.push_back(s);
        }
    
        for(int i = s.size()-1; i >= 0; i--)
        {
            string cut = s.substr(0, i);
            string left = s.substr(i);
            if(wordDict.find(left) != wordDict.end())
            {
                vector<string> ans = wordBreakCore(cut, wordDict);
                for(int j = 0; j < ans.size(); j++)
                {
                    ans[j] += " " + left;
                }
                res.insert(res.begin(), ans.begin(), ans.end());
            }
        }
        table[s] = res;
        return res;
    }
    
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        return wordBreakCore(s, wordDict);
    }

};