#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        // we will take a stack in which we will push all the elements
        stack<int> s;
        // now we will make an nge array to store the next greater element array
        vector<int> nge(n, -1);
        // now we will move from backward, with all the element repeated as this is a circular array
        for (int i = 2 * n - 1; i >= 0; i--)
        {
            // first thing we do is remove element from the stack until current element is greater then the top of the stack
            // so stack is maintained as the greatest element at the last and number that is next greater to the
            // current element is place at the top
            // if an element is greater then the stack top we will remove element from stack top util stack top element is greater then the current element
            while (!s.empty() && s.top() <= nums[i % n])
            {
                s.pop();
            }

            // now s.top() has the next greater element, so if i < n we will assing the next greater element to that index
            if (i < n && !s.empty())
            {
                nge[i] = s.top();
            }

            // finally we will push the current element at the top of stack
            s.push(nums[i % n]);
        }

        return nge;
    }
};

class Solution2
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> s; // in this stack we will store the index of the element, with element in decreasing order
        // we will store the index in s
        vector<int> nge(n, -1);

        for (int i = 0; i < 2 * n; i++)
        {
            int num = nums[i % n];
            // we will check if current element is greater then then stack top
            // if it is, then pop element from stack until we don't get the element in the stack that is greater then
            // then current element. And for all the element pop, current element is the next greater element
            while (!s.empty() && nums[s.top()] < num)
            {
                // bcz num is next greate element for s.top()
                nge[s.top()] = num;
                s.pop();
            }
            // in the circular array we will push the elements that are in the first array
            if (i < n)
                s.push(i);
        }

        return nge;
    }
};
