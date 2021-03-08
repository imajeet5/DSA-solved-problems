#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue)
    {
        //type, color, name
        // item
        int ruleKeyIdx = 0;
        int matching = 0;
        if (ruleKey == "color")
            ruleKeyIdx = 1;
        if (ruleKey == "name")
            ruleKeyIdx = 2;
        for (int i = 0; i < items.size(); i++)
        {
            vector<string> currItem = items[i];
            if (currItem[ruleKeyIdx] == ruleValue)
            {
                matching++;
            }
        }
        return matching;
    }
};
