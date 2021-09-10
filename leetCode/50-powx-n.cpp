#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {

        double ans = 1.0;
        long long p = n;
        if (p < 0)
            p = -1 * p;

        while (p > 0)
        {
            // if power is odd
            if (p % 2 == 1)
            {
                ans = ans * x;
                p = p - 1;
            }
            else
            {
                // if power is even
                x = x * x;
                p = p / 2;
            }
        }

        if (n < 0)
            ans = (double)(1.0) / (double)(ans);

        return ans;
    }
};