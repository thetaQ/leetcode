#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums)
    {
        /* sort first */
        sort(nums.begin(), nums.end());
        vector<vector<int> > results;
        for(size_t a = 0; a < nums.size(); a++)
        {
            if(a > 0 && nums[a] == nums[a - 1])   /* remove duplicate */
                continue;
            size_t b = a + 1, c = nums.size() - 1;
            while(b < c)
            {
                int sum = nums[a] + nums[b] + nums[c];
                if(sum == 0)
                {
                    results.push_back(vector<int> {nums[a], nums[b], nums[c]});
                    b++;
                    c--;
                    /* remove duplicate */
                    while(b < c && nums[b] == nums[b-1])
                        b++;
                    while(b < c && nums[c] == nums[c+1])
                        c--;
                }
                else if(sum < 0)
                {
                    b ++;
                }
                else
                {
                    c--;
                }
            }
        }
        return results;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> results = solution.threeSum(nums);
    for(vector<int> v: results)
    {
        for(int num: v)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}