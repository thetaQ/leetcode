#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection()
    {
        srand((unsigned)time(0));
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val)
    {
        bool flag = true;
        if(val_to_indexs.count(val) != 0)
            flag = false;
        val_to_indexs[val].push_back(vals.size());
        vals.push_back(val);
        return flag;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val)
    {
        if(val_to_indexs.count(val) == 0)
            return false;
        
        int index_v_size = val_to_indexs[val].size();
        int index = val_to_indexs[val][index_v_size-1];
        if(index != vals.size()-1)
        {
            for(int i = 0; i < val_to_indexs[vals[vals.size()-1]].size(); i++)
            {
                if(val_to_indexs[vals[vals.size()-1]][i] == vals.size()-1)
                {
                    val_to_indexs[vals[vals.size()-1]][i] = index;
                    break;
                }
            }
            int tmp = vals[index];
            vals[index] = vals[vals.size()-1];
            vals[vals.size()-1] = tmp;
        }
        vals.pop_back();
        val_to_indexs[val].pop_back();
        if(val_to_indexs[val].size() == 0)
        {
            val_to_indexs.erase(val_to_indexs.find(val));
        }
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom()
    {
        return vals[rand()%vals.size()];    
    }
private:
    unordered_map<int, vector<int>> val_to_indexs;
    vector<int> vals;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */