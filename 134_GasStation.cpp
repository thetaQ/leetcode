#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int total_gas = 0;
        int total_cost = 0;
        int start = 0;
        for(int i = 0; i < gas.size(); i++)
        {
            sum += gas[i] - cost[i];
            total_gas += gas[i];
            total_cost += cost[i];
            
            if(sum < 0)
            {
                sum = 0;
                start = i + 1;
            }
        }
        
        if(total_gas < total_cost)
            return -1;
        return start;
    }
};