#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

bool checkSubString(string str, int i, string x)
{
    int n = x.length();
    for (int j = 1; j < n; j++, i++)
        if (str[i] != x[j])
            return false;
    return true;
}

int my_strstr(string str, string x)
{
    int n = str.length();
    for (int i = 0; i < n; i++)
        if (str[i] == x[0] && checkSubString(str, i + 1, x))
            return i;
    return -1;
}

int main(int argc, char const *argv[])
{
    // freopen("_input.txt", "r", stdin);
    int t = 0;
    cin >> t;
    while (t--)
    {
        string s, x;
        cin >> s >> x;
        cout << my_strstr(s, x) << endl;
    }
    return 0;
}