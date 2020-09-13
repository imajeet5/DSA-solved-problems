#include <bits/stdc++.h>

using namespace std;

//for every divisor of n
// check if the prefix of that length is the pattern
// if yes, then return true else continue

bool isPattern(string subs_str, string s)
{
    int maxPos = s.size() / subs_str.size();
    for (int i = 0; i < maxPos; i++)
    {
        string subObtained = s.substr(i * subs_str.size(), subs_str.size());
        if (subObtained != subs_str)
            return false;
    }
    return true;
}

bool repeatedSubstringPattern(string s)
{
    int n = s.size();
    if (n <= 1)
        return false;

    string str1;
    str1.push_back(s[0]);
    if (isPattern(str1, s))
        return true;
    for (int i = 2; i * i <= n; i++)
    {
        // is a divisor of n
        if (n % i == 0)
        {
            string pat1 = s.substr(0, i);
            string pat2 = s.substr(0, n / i);
            if (isPattern(pat1, s) || isPattern(pat2, s))
                return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
   
    // string s = "abaababaab";
    string s = "abcabcabcabc";
    bool val = repeatedSubstringPattern(s);
    string res = val ? "true" : "false";
    cout << res << endl;
    return 0;
}