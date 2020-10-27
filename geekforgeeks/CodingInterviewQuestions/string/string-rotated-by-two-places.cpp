#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

string rotateStringACW(string s, int t)
{

    while (t--)
    {
        char first = s.at(0);
        s += first;
        s = s.substr(1, s.length());
    }
    return s;
}

string rotateStringCW(string s, int t)
{
    while (t--)
    {

        s = *(s.end() - 1) + s.substr(0, s.length() - 1);
    }
    return s;
}

bool isStringRotated(string oS, string nS)
{
    string s_acw = rotateStringACW(oS, 2);
    if (s_acw == nS)
    {
        return true;
    }
    string s_cw = rotateStringCW(oS, 2);
    if (s_cw == nS)
    {
        return true;
    }
   return false;
}

int main(int argc, char const *argv[])
{
    // freopen("_input.txt", "r", stdin);
    int t = 0;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

        cout << isStringRotated(s1, s2) << endl;
    }
    return 0;
}