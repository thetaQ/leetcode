#include <iostream>
#include <queue>
using namespace std;

class MedianFinder {
public:
    
    // Adds a number into the data structure.
    void addNum(int num)
    {
        if(max_heap.size() == min_heap.size())
        {
            if(min_heap.size() > 0 && num > min_heap.top())
            {
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(num);
            }
            else
            {
                max_heap.push(num);
            }
        }
        else
        {
            if(num < max_heap.top())
            {
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(num);
            }
            else
            {
                min_heap.push(num);
            }
        }
    }
    
    // Returns the median of current data stream
    double findMedian()
    {
        if(max_heap.empty())
            return 0.0;
        if(max_heap.size() == min_heap.size())
        {
            return (double)(max_heap.top() + min_heap.top()) / 2.0;
        }
        else
        {
            return (double)max_heap.top();
        }
    }
    
private:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int> > min_heap;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();