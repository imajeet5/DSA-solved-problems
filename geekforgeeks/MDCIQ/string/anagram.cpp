#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

string anagram(string s1, string s2)
{
    if (s1.length() != s2.length())
    {
        return "NO";
    }
    unordered_map<char, int> map_s1;
    unordered_map<char, int> map_s2;

    for (auto it : s1)
    {
        map_s1[it]++;
    }
    for (auto it : s2)
    {
        map_s2[it]++;
    }
    for (auto it : map_s1)
    {
        if (map_s2[it.first] != it.second)
        {
            return "NO";
        }
    }
    return "YES";
}

int main(int argc, char const *argv[])
{
    // freopen("_input.txt", "r", stdin);
    int t = 0;
    cin >> t;
    while (t--)
    {
        string s1;
        string s2;
        cin >> s1 >> s2;
        cout << anagram(s1, s2) << endl;
    }
    return 0;
}