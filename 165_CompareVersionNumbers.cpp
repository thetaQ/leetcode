#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2)
    {
        int index1 = 0, index2 = 0;
        int size1 = version1.size();
        int size2 = version2.size();

        int v1 = 0, v2 = 0;
        while(index1 < size1 || index2 < size2)
        {
            while(index1 < size1 && version1[index1] != '.')
            {
                v1 = v1 * 10 + version1[index1]- '0';
                index1 ++;
            }
            while(index2 < size2 && version2[index2] != '.')
            {
                v2 = v2 * 10 + version2[index2] - '0';
                index2 ++;
            }
            if(v1 < v2)
            {
                return -1;
            }
            else if(v1 > v2)
            {
                return 1;
            }
            else
            {
                v1 = 0;
                v2 = 0;
                while(index1 < size1 && version1[index1] == '.')
                    index1 ++;
                while(index2 < size2 && version2[index2] == '.')
                    index2 ++;
            }
        }
        return 0;
    }
};