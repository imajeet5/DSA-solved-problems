
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int maxWealth = INT_MIN;
        for (int i = 0; i < accounts.size(); i++)
        {
            int w = 0;
            for (int j = 0; j < accounts[0].size(); j++)
            {
                w += accounts[i][j];
            }
            maxWealth = max(w, maxWealth);
        }

        return maxWealth;
    }
};