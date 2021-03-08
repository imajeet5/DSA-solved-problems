#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int subtractProductAndSum(int n)
    {
        int num = n;
        int product = 1;
        int sum = 0;
        while (num)
        {
            int lastdigit = num % 10;
            num = num / 10;
            product *= lastdigit;
            sum += lastdigit;
        }
        return product - sum;
    }
};
