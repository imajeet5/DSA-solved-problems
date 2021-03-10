#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        string s1;
        string s2;
        for (auto w : word1)
            s1 += w;
        for (auto w : word2)
            s2 += w;
        if (s1.size() != s2.size())
            return false;

        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i])
                return false;
        }

        return true;
    }
};