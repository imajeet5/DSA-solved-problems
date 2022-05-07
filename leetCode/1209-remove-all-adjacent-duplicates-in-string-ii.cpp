#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string removeDuplicates(string s, int k)
    {
        int i = 0, n = s.size();
        vector<int> count(n);

        for (int j = 0; j < n; j++)
        {
            s[i] = s[j];
            if (i > 0 && s[j] == s[i - 1])
            {
                count[i] = count[i - 1] + 1;
                if (count[i] == k)
                {
                    i -= k;
                }
            }
            else
            {
                count[i] = 1;
            }
        }

        return s.substr(0, i);
    }
};
