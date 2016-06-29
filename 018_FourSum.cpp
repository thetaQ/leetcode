#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target)
    {
        /* sort first */
        sort(nums.begin(), nums.end());
        vector<vector<int> > results;
        for(size_t a = 0; a < nums.size(); a++)
        {
            if(a > 0 && nums[a] == nums[a - 1])   /* remove duplicate */
                continue;
            for(size_t d = nums.size()-1; d > a; d--)
            {
                if(d < nums.size()-1 && nums[d] == nums[d+1])
                    continue;
                
                size_t b = a + 1, c = d - 1;
                while(b < c)
                {
                    int sum = nums[a] + nums[b] + nums[c] + nums[d];
                    if(sum == target)
                    {
                        results.push_back(vector<int> {nums[a], nums[b], nums[c], nums[d]});
                        b++;
                        c--;
                        /* remove duplicate */
                        while(b < c && nums[b] == nums[b-1])
                            b++;
                        while(b < c && nums[c] == nums[c+1])
                            c--;
                    }
                    else if(sum < target)
                    {
                        b ++;
                    }
                    else
                    {
                        c--;
                    }
                }
            }
           
        }
        return results;
    }
};