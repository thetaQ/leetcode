#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int hIndex(vector<int>& citations) 
    {
        int n = citations.size();
        vector<int> htable(n+1, 0);
        for(int i = 0; i < n; ++i)
        {
            if(citations[i] >= n)
                htable[n] ++;
            else
                htable[citations[i]] ++;
        }
        int hindex = 0;
        for(int i = n; i >= 0; i--)
        {
            hindex += htable[i];
            if(hindex >= i)
                return i;
        }
        return 0;
    }
};