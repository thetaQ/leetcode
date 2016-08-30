#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
    NumArray(vector<int> &nums) {
        data = nums;
        for(int i = 1; i < nums.size(); i++)
        {
            data[i] += data[i-1];
        }
    }

    int sumRange(int i, int j) {
        if(i > j || i < 0 || j >= data.size())
            return 0;
        return data[j] - (i > 0 ? data[i-1] : 0);
    }
private:
    vector<int> data;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);