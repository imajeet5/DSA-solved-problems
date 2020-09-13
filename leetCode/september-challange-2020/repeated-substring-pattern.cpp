#include <bits/stdc++.h>

using namespace std;

bool repeatedSubstringPattern(string s)
{
    string subs = "";
    string next;
    subs += s.at(0);
    int i = 1;
    while (i < s.size())
    {
        next = s.substr(i, i);
        if (subs == next)
        {
            break;
        }
        subs += s.at(i);
        i++;
    }
    if (i == s.size())
    {
        return false;
    }
    if((2*i) == s.size() && subs == next){
        return true;
    }
    int len = i;
    i = i + len;
    if (i + len > s.size())
    {
        return false;
    }
    while (i + len <= s.size())
    {
        next = s.substr(i, len);
        if (subs != next)
        {
            return false;
        }
        i += len;
    }

    return true;
}

int main(int argc, char const *argv[])
{
    string s = "abaababaab";
    bool val = repeatedSubstringPattern(s);
    string res = val ? "true" : "false";
    cout << res << endl;
    return 0;
}