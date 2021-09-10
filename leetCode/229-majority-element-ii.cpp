#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int e1 = -1, e2 = -1, c1 = 0, c2 = 0;

        // we will count both element 1 and element 2
        // if any other element is there other than element 1 or element 2 we will reduce the count
        // if count becomes zero we will update the elements
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == e1)
            {
                // we will increase the count of the element 1
                c1++;
            }
            else if (nums[i] == e2)
            {
                // we will increase the count of the element 2
                c2++;
            }
            else if (c1 == 0)
            {
                // if the count of element 1 is zero we will update the element 1
                e1 = nums[i];
                c1 = 1;
            }
            else if (c2 == 0)
            {
                e2 = nums[i];
                c2 = 1;
            }
            else
            {
                c1--;
                c2--;
            }
        }

        vector<int> ans;

        c1 = c2 = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == e1)
            {
                c1++;
            }
            else if (nums[i] == e2)
            {
                c2++;
            }

            if (c1 > nums.size() / 3)
            {
                ans.push_back(e1);
            }
            if (c2 > nums.size() / 3)
            {
                ans.push_back(e2);
            }
        }
        return ans;
    }
};