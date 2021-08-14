#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {
        unordered_map<string, string> mpp;
        vector<string> pd;
        for (int i = 0; i < paths.size(); i++)
        {
            pd.push_back(paths[i][1]);
            mpp[paths[i][0]] = paths[i][1];
        }

        for (auto el : pd)
        {
            // if element is not the source of anything
            if (mpp.find(el) == mpp.end())
            {
                return el;
            }
        }

        return "";
    }
};