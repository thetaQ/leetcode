#include <iostream>
#include <queue>
using namespace std;

class Stack {
public:
	// Push element x onto stack.
	void push(int x)
	{
		if (!q1.empty())
			q1.push(x);
		else
			q2.push(x);
	}

	// Removes the element on top of the stack.
	void pop()
	{
		if (!q1.empty())
		{
			int size = q1.size();
			for (int i = 1; i < size; i++)
			{
				q2.push(q1.front());
				q1.pop();
			}
			q1.pop();
		} 
		else
		{
			int size = q2.size();
			for (int i = 1; i < size; i++)
			{
				q1.push(q2.front());
				q2.pop();
			}
			q2.pop();
		}
	}

	// Get the top element.
	int top()
	{
		int res = 0;
		if (!q1.empty())
		{
			int size = q1.size();
			for (int i = 1; i < size; i++)
			{
				q2.push(q1.front());
				q1.pop();
			}
			res = q1.front();
			q2.push(res);
			q1.pop();
		}
		else
		{
			int size = q2.size();
			for (int i = 1; i < size; i++)
			{
				q1.push(q2.front());
				q2.pop();
			}
			res = q2.front();
			q1.push(res);
			q2.pop();
		}
		return res;
	}

	// Return whether the stack is empty.
	bool empty()
	{
		return q1.empty() && q2.empty();
	}

private:
	queue<int> q1, q2;
};

int main(void)
{	
	Stack s;
	s.push(1);
	s.pop();
	cout << s.empty() << endl;
	return 0;
}