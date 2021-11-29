#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int nextGreaterElement(int n)
    {
        // first we conver the number to string
        string s = to_string(n);
        if (s.length() == 0)
            return -1;

        // find the first decreasing digit from the right
        int i = s.length() - 2;
        while (i >= 0 && s[i] >= s[i + 1])
            i--;

        if (i == -1)
        {
            return -1; // if we cannot found the decreasing digit, then number is already the greatest
        }
        // are the number is already sorted we will reverse the number that part of number
        reverse(s.begin() + i + 1, s.end());

        // now we will search to the right side for the next greater digit and swap left with that to make it greater
        for (int j = i + 1; j < s.length(); j++)
        {
            if (s[j] > s[i])
            {
                swap(s[i], s[j]);
                break;
            }
        }

        long ng = stol(s);

        return ng == n || ng > INT_MAX ? -1 : ng;
    }
};