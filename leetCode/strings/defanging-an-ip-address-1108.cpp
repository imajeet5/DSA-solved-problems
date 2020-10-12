#include <bits/stdc++.h>

using namespace std;

string defangIPaddr(string address)
{
    string ans = "";
    for (auto c : address)
    {
        if (c == '.')
            ans += "[.]";
        else
            ans.push_back(c);
    }
    return ans;
}

string defangIPaddr2(string a)
{
    return regex_replace(a, regex("\\."), "[.]");
}

int main(int argc, char const *argv[])
{
    string ipadd = "1.1.1.1";
    string ans = defangIPaddr2(ipadd);
    cout << ans << endl;
    return 0;
}