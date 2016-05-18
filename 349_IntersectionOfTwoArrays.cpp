#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
    
    public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> num_tabel; 
        vector<int> result;
        for(auto i: nums1)
        {
            //add number of nums1 to table
            num_tabel[i] = 1; 
        }

        for(auto i: nums2)
        {
            auto it = num_tabel.find(i);
            if(it != num_tabel.end())
            {
                //find, delete it from num_tabel and add to result vector
                result.push_back(i);
                num_tabel.erase(it);
            }
        }
        return result;
    }
};

int main(void)
{
    Solution solution;
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> result = solution.intersection(nums1, nums2);
    for(auto i : result)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
