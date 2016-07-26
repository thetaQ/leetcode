#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x)
    {
        number_stack.push(x);
        if(!min_stack.empty() && x > min_stack.top())
        {
            min_stack.push(min_stack.top());
        }
        else
        {
            min_stack.push(x);
        }

    }
    
    void pop()
    {
        number_stack.pop();
        min_stack.pop();
    }
    
    int top()
    {
        return number_stack.top();    
    }
    
    int getMin()
    {
        return min_stack.top();    
    }
    
private:
    stack<int> number_stack;
    stack<int> min_stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */