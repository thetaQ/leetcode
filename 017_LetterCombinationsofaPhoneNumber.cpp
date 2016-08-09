#include <iostream>
#include <string>
#include <vector>
using namespace std;

void letterCombinationsCore(vector<string>& result, string digits, vector<string>& dict, int dict_index, string& one_solution)
{
    if(dict_index == digits.size())
    {
        result.push_back(one_solution);
        return;
    }
    for(int i = 0; i < dict[dict_index].size(); i++)
    {
        one_solution.push_back(dict[dict_index][i]);
        letterCombinationsCore(result, digits, dict, dict_index+1, one_solution);
        one_solution.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> dict = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> dicts;
    vector<string> res;
    string one_solution = "";
    for(int i = 0; i < digits.size(); ++i)
    {
        dicts.push_back(dict[digits[i]-'0']);
    }
    letterCombinationsCore(res, digits, dicts, 0, one_solution);
    return res;
}