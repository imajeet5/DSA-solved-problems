#include <bits/stdc++.h>

using namespace std;

bool repeatedSubstringPattern(string s)
{
    int len = s.size();
    for (int i = len / 2; i >= 1; i--)
    {
        if (len % i == 0)
        {
            int num_repeats = len / i;
            string substr = s.substr(0, i);
            string new_str;
            for (int j = 0; j < num_repeats; j++)
            {
                new_str += substr;
            }
            if (s == new_str)
            {
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{

    string s = "abaababaab";
    // string s = "abcabcabcabc";
    bool val = repeatedSubstringPattern(s);
    string res = val ? "true" : "false";
    cout << res << endl;
    return 0;
}