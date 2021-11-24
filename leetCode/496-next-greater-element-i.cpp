#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> result;
        // we will take a map in which we push next greater element for every element
        unordered_map<int, int> mp;
        // we will take a stack in which we will push the next greater element
        stack<int> ng;
        // now we will loop over nums2 from the end
        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            // first we will check if stack is not empty
            if (ng.empty())
            {
                // there is no element greater then the current element
                mp[nums2[i]] = -1;
                // and push the current element in the stack as it is current next greater element
                ng.push(nums2[i]);
            }
            else
            {
                // if stack is not empty, get the top element of the stack
                int top = ng.top();
                // if current element is lesser then the top element, then stack top element is the next greater element
                if (nums2[i] < top)
                {
                    mp[nums2[i]] = top;
                    ng.push(nums2[i]);
                }
                else
                {
                    // we will pop the elements from the stack until we don't find the greater element then current in the stack
                    while (true)
                    {
                        if (ng.empty())
                        {
                            mp[nums2[i]] = -1;
                            ng.push(nums2[i]);
                            break;
                        }
                        else
                        {
                            int t = ng.top();

                            if (nums2[i] < t)
                            {
                                mp[nums2[i]] = t;
                                ng.push(nums2[i]);
                                break;
                            }
                            else
                            {
                                ng.pop();
                            }
                        }
                    }
                }
            }
        }

        for (auto n : nums1)
        {
            result.push_back(mp[n]);
        }

        return result;
    }
};

class Solution2
{
public:
    vector<int> nextGreaterElement(vector<int> &findNums, vector<int> &nums)
    {
        stack<int> s;
        unordered_map<int, int> m;
        for (int n : nums)
        {
            // we will store all the number that are less then the next greater element, and pop them as soon as
            // we found the the next greater
            while (!s.empty() && s.top() < n)
            {
                m[s.top()] = n;
                s.pop();
            }
            // then we will push the current element into the stack
            s.push(n);
        }

        vector<int> ans;
        for (int n : findNums)
        {
            ans.push_back(m.count(n) ? m[n] : -1);
        }

        return ans;
    }
};
