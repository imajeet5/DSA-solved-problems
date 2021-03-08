#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numJewelsInStones(string J, string S)
    {
        unordered_map<char, int> stones;
        for (auto ch : S)
        {
            stones[ch]++;
        }
        int count = 0;
        for (auto ch : J)
        {
            count += stones[ch];
        }

        return count;
    }
};