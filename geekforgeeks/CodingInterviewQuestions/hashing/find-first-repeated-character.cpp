#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void doSomething(string str)
{
    unordered_set<char> uniq;
    for (int i = 0; i < str.length(); i++)
    {
        char c = str[i];

        if (uniq.find(c) != uniq.end())
        {

            cout << c << endl;
            return;
        }
        uniq.insert(c);
    }
    cout << -1 << endl;
}

int main(int argc, char const *argv[])
{
    // freopen("_input.txt", "r", stdin);
    int t = 0;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        doSomething(s);
    }
    return 0;
}