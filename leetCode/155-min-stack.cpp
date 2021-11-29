#include <bits/stdc++.h>

using namespace std;

class MinStack
{
public:
    stack<int> elements;
    stack<int> mins;

    MinStack()
    {
    }

    void push(int val)
    {
        elements.push(val);
        if (mins.empty())
        {
            mins.push(val);
        }
        else
        {
            if (val <= mins.top())
            {
                mins.push(val);
            }
            else
            {
                mins.push(mins.top());
            }
        }
    }

    void pop()
    {
        elements.pop();
        mins.pop();
    }

    int top()
    {
        return elements.top();
    }

    int getMin()
    {
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */