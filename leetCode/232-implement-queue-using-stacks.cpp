#include <bits/stdc++.h>

using namespace std;

class MyQueue
{
public:
    stack<int> nums;
    stack<int> helper;

    MyQueue()
    {
    }

    void push(int x)
    {
        // first we will invert the nums stack to the helper
        while (!nums.empty())
        {
            helper.push(nums.top());
            nums.pop();
        }

        nums.push(x);
        // now put all the element from helper to nums again
        while (!helper.empty())
        {
            nums.push(helper.top());
            helper.pop();
        }
    }

    int pop()
    {
        int n = nums.top();
        nums.pop();
        return n;
        }

    int peek()
    {
        return nums.top();
    }

    bool empty()
    {
        return nums.empty();
    }
};