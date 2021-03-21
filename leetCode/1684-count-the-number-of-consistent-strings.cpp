#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        set<char> str_letters;
        int ans = 0;
        for (int i = 0; i < allowed.size(); i++)
        {
            str_letters.insert(allowed[i]);
        }

        for (int i = 0; i < words.size(); i++)
        {
            string curr = words[i];
            int letter_present = 0;
            for (auto ch : curr)
            {
                // if the element is present in the set
                if (str_letters.count(ch) != 0)
                {
                    letter_present++;
                }
            }
            if (letter_present == curr.size())
            {
                ans++;
            }
        }

        return ans;
    }
};