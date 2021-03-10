#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int balancedStringSplit(string s)
    {

        int rCount = 0;
        int lCount = 0;
        int total = 0;
        for (auto c : s)
        {
            if (c == 'R')
            {
                rCount++;
            };
            if (c == 'L')
            {
                lCount++;
            }
            if (rCount == lCount)
            {
                total++;
                rCount = 0;
                lCount = 0;
            }
        }

        return total;
    }
};
