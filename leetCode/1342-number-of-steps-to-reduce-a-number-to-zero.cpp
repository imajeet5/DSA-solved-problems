#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numberOfSteps(int num)
    {
        int count = 0;
        while (num != 0)
        {
            if (num % 2 == 0)
            {
                num = num / 2;
            }
            else
            {
                num--;
            }
            count++;
        }
        return num;
    }
};