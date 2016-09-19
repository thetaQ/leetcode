#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canCrossCore(vector<int>& stones, int cur_pos, int last_jump)
    {
        for(int i = cur_pos + 1; i < stones.size(); i++)
        {
            int jump = stones[i] - stones[cur_pos];
            if(jump < last_jump - 1)
                continue;
            if(jump > last_jump + 1)
                return false;
            if(canCrossCore(stones, i, jump))
                return true;
        }
        return cur_pos == stones.size() - 1;
    }

    bool canCross(vector<int>& stones)
    {
        return canCrossCore(stones, 0, 0);
    }
};