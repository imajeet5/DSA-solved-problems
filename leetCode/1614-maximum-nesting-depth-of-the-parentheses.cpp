#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {
        // so we have to count the max parentheses that are open at a time
        int count = 0, res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                count++;
                res = max(count, res);
            }
            else if (s[i] == ')')
            {
                count--;
            }
        }

        return res;
    }
};