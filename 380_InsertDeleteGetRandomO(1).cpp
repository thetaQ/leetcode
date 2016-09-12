#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet()
    {
        srand((unsigned)time(0));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if(val_to_index.count(val))
            return false;
        val_to_index[val] = vals.size();
        vals.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if(val_to_index.count(val) == 0)
            return false;
        
        int index = val_to_index[val];
        int size = vals.size();
        if(index != size - 1)
        {
            val_to_index[vals[size-1]] = index;
            int tmp = vals[index];
            vals[index] = vals[size - 1];
            vals[size - 1] = tmp;
        }
        vals.pop_back();
        val_to_index.erase(val_to_index.find(val));
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom()
    {
        return vals[rand()%vals.size()];
    }
private:
    unordered_map<int, int> val_to_index;
    vector<int> vals;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

int main()
{
    RandomizedSet rs;
    rs.insert(0);
    rs.insert(1);
    rs.remove(0);
    rs.insert(2);
    rs.remove(1);
    cout << rs.getRandom() << endl;
    return 0;
}
