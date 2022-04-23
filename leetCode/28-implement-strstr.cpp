#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> getPrefixArray(string pattern)
    {
        vector<int> lps(pattern.size());
        // we will keep two pointer i and j.
        // i will go till the end whereas j will stay at the start and start from there
        int i = 1, j = 0;
        // we will loop until i reaches the end
        while (i < pattern.size())
        {
            // now if character at i and j are the same, we will put j+1 at lps
            if (pattern[i] == pattern[j])
            {
                lps[i] = j + 1;
                // now increase both i and j
                i++;
                j++;
            }
            else
            {
                // if the pattern did not match
                // then if j is not zero
                if (j != 0)
                {
                    j = lps[j - 1];
                }
                else
                {
                    // if j is also zero
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

    int strStr(string haystack, string needle)
    {
        vector<int> lps = getPrefixArray(needle);
        // we will take two pointer i and j, i for haystack and j for needle
        int i = 0, j = 0;
        while (i < haystack.size() && j < needle.size())
        {
            // first we match if the current character of both matching
            if (haystack[i] == needle[j])
            {
                // increase both i and j
                i++;
                j++;
            }
            else
            {
                // if the characters are not matching
                // not if j is not equal to zero
                if (j != 0)
                {
                    // move j at the position define by lps, this is the position having same suffix as prefix
                    j = lps[j - 1];
                    // then start matching from this position
                }
                else
                {
                    // if j is zero, then just move i
                    i++;
                }
            }
        }

        // if the end, if j has come to the end
        if (j == needle.size())
        {
            return i - j;
        }

        return -1;
    }
};