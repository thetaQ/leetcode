#include <iostream>
#include <vector>
using namespace std;

bool mycmp(pair<int, int>& a, pair<int, int>& b)
{
    if(a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes)
    {
        if(envelopes.size() == 0)
            return 0;
        sort(envelopes.begin(), envelopes.end(), mycmp);
        
        //根据高度，求最长递增子序列
        vector<int> dp;
        for(int i = 0; i < envelopes.size(); i++)
        {
            int left = 0, right = dp.size()-1;
            int target = envelopes[i].second;
            while(left <= right)
            {
                int mid = left + (right - left) / 2;
                if(dp[mid] < target)
                    left = mid + 1;
                else if(dp[mid] > target)
                    right = mid - 1;
                else
                {
                    left = mid;
                    break;
                }
            }
            if(left >= dp.size())
                dp.push_back(target);
            else
                dp[left] = target;
        }
        
        return dp.size();
    }
};