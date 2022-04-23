#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int romanToInt(string s)
    {
        // in this we will traverse from the back and start adding number.
        // as soon as we found a number for which next number is greater we will subtract that number
        unordered_map<char, int> romans = {{'I', 1},
                                           {'V', 5},
                                           {'X', 10},
                                           {'L', 50},
                                           {'C', 100},
                                           {'D', 500},
                                           {'M', 1000}};
        // we will put the last number in the answers
        int ans = romans[s.back()];

        for (int i = s.length() - 2; i > 0; i--)
        {
            // first we check if current letter next is greater
            if (romans[s[i]] < romans[s[i + 1]])
            {
                // we will subtract the current number from the answer
                ans -= romans[s[i]];
            }
            else
            {
                // we will add the current number to answers
                ans += romans[s[i]];
            }
        }

        return ans;
    }
};