#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        if (n == 2)
            return "11";
        string s = "11";
        // we will start build string from 3 and onwards
        for (int i = 3; i <= n; i++)
        {
            // first we will take a temporary string
            string curr = "";
            int counter = 1;
            // we will add one extra character in the end of string
            // as when it goes to the end it will skip the last character
            s = s + '$';

            for (int j = 1; j < s.length(); j++)
            {
                // if the current character is same as the previous character then
                // we will increase the counter

                if (s[i] == s[i - 1])
                {
                    counter++;
                }
                else
                {
                    // else we will create the number for the current count
                    curr += to_string(counter);
                    curr += s[i - 1];
                    counter = 1;
                }
            }

            // current string will become the main string
            s = curr;
        }

        return s;
    }
};