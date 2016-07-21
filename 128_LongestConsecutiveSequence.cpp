#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_map<int, int> maps;
        int max_length = 0;
        for(int num: nums)
        {
            if(maps.find(num) == maps.end())
            {//do not find
                int left = maps.find(num-1) == maps.end() ? 0 : maps[num-1];
                int right = maps.find(num+1) == maps.end() ? 0 : maps[num+1];
                int sum = left + right + 1;
                maps[num] = sum;
                max_length = max(max_length, sum);

                maps[num-left] = sum;
                maps[num+right] = sum;
            }
        }
        return max_length;
    }
};