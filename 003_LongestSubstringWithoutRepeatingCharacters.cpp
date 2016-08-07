#include <iostream>
#include <string>
#include <vector>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    int length = s.size();
    if(length == 0)
        return 0;
    int dp[length];
    memset(dp, 0, sizeof(dp));
    vector<int> lastappear(256, -1);
    int max_len = 1;
    dp[0] = 1;
    lastappear[s[0]] = 0;
    
    for(int i = 1; i < length; i++)
    {
        if(lastappear[s[i]] <= i - dp[i-1] - 1)
        {
            dp[i] = dp[i-1] + 1;
            max_len = max(max_len, dp[i]);
        }
        else
        {
            dp[i] = i - lastappear[s[i]];
            max_len = max(max_len, dp[i]);
        }
        lastappear[s[i]] = i;
    }
    return max_len;
}

int main()
{
    cout << lengthOfLongestSubstring("au") << endl;
    return  0;
}