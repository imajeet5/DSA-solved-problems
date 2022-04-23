#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;

        int n = s.length();
        // we will create a count array in which we will increase the occurrence if it exist in s
        // and decrease the count if it exist in t
        int count[26] = {0};
        for (int i = 0; i < n; i++)
        {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        // now loop over count and check if all the values are zero
        for (int i = 0; i < 26; i++)
        {
            if (count[i])
                return false;
        }
        return true;
    }
};