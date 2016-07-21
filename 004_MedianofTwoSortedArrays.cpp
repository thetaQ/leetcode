#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    double find_kth(int *nums1, int m, int *nums2, int n, int k)
    {
        if(m > n)
        {
            return find_kth(nums2, n, nums1, m, k);
        }

        if(m == 0)
        {
            return nums2[k-1];
        }

        int pa = min(m, k/2);
        int pb = k - pa;

        if(nums1[pa-1] < nums2[pb-1])
        {
            return find_kth(nums1+pa, m-pa, nums2, n, k-pa);
        }
        else
        {
            return find_kth(nums1, m, nums2+pb, n-pb, k-pb);
        }
    }

    double findMedianSortedArrays(int *nums1, int m, int *nums2, int n)
    {
        int total_length = m + n;
        if(total_length & 1)
        {
            return find_kth(nums1, m, nums2, n, (total_length+1)/2);
        }
        else
        {
            return (find_kth(nums1, m, nums2, n, total_length/2) + find_kth(nums1, m, nums2, n, total_length/2 + 1))/2.0;
        }
    }
};