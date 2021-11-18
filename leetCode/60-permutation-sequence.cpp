#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        // first we make an array of numbers and make a factorial for the digits
        // we will create the first factorial for n-1 digits
        vector<int> nums;
        int fact = 1;
        string ans;
        for (int i = 1; i < n; i++)
        {
            nums.push_back(i);
            fact *= i;
        }
        k = k - 1;
        // now we will loop until nums has elements
        nums.push_back(n);
        while (true)
        {
            // first we get the index of element which can be fixed
            int idx = k / fact;
            ans += to_string(nums[idx]);

            // now remove the element from nums
            nums.erase(nums.begin() + idx);
            if (nums.size() == 0)
            {
                break;
            }

            // now the value of k will be updated
            k = k % fact;
            // value of fact will be reduce based on the remaining elements
            fact = fact / nums.size();
        }

        return ans;
    }
};