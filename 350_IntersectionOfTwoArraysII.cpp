#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    //solution one, use map
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int, int> number_table; 
        vector<int> result;
        for(auto n: nums1)
        {
            unordered_map<int, int>::iterator it = number_table.find(n);
            if(it == number_table.end())
            {
                //do not find
                number_table[n] = 1;
            }
            else
            {
                number_table[n] ++;
            }
        }
            
        for(auto n: nums2)
        {
            unordered_map<int, int>::iterator it = number_table.find(n); 
            if(it != number_table.end())
            {
                //find
                result.push_back(n);
                number_table[n] --;
                if(number_table[n] == 0)
                    number_table.erase(n);
            }
        }
        return result;
    }


    static bool comp(const int& a, const int& b)
    {
        return a < b; 
    }

    //solution two, if the array is sorted 
    vector<int> intersect_2(vector<int>& nums1, vector<int>& nums2) 
    {
        sort(nums1.begin(), nums1.end(), comp);
        sort(nums2.begin(), nums2.end(), comp);
        
        int size1 = nums1.size();
        int size2 = nums2.size();
        int p1 = 0, p2 = 0;
        vector<int> result;

        while(p1 < size1 && p2 < size2)
        {
            if(nums1[p1] == nums2[p2]) 
            {
                result.push_back(nums1[p1]);
                p1 ++;
                p2 ++;
            }
            else if(nums1[p1] < nums2[p2])
            {
                p1 ++;
            }
            else 
            {
                p2 ++;
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
    vector<int> ret = solution.intersect_2(nums1, nums2);
    for(auto n: ret)
    {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}
