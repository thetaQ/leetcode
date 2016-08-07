#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>

using namespace std;

void generate(vector<string>& result, string s, int leftRem, int rightRem)
{
    if(leftRem == 0 && rightRem == 0)
    {
        result.push_back(s);
    }
    else
    {
        if(leftRem > 0)
        {
            generate(result, s + "(", leftRem - 1, rightRem);
        }
        if(rightRem > leftRem)
        {
            generate(result, s + ")", leftRem, rightRem - 1);
        }
    }
}

vector<string> generateParenthesis(int n)
{
    string s;
    vector<string> result;
    generate(result, s, n, n);
    return result;
}

int main()
{
    vector<string> result = generateParenthesis(3);
    for(string s: result)
    {
        cout << s << endl;
    }
    return  0;
}