#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int highestAlt = 0;
        int currentAlt = 0;
        for (auto g : gain)
        {
            currentAlt += g;
            highestAlt = max(highestAlt, currentAlt);
        }
        return highestAlt;
    }
};