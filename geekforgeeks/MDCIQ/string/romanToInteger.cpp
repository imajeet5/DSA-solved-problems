#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int romanToInteger(string rm)
{
    int n = rm.length();
    unordered_map<char, int> romans;
    romans.insert(make_pair('I', 1));
    romans.insert(make_pair('V', 5));
    romans.insert(make_pair('X', 10));
    romans.insert(make_pair('L', 50));
    romans.insert(make_pair('C', 100));
    romans.insert(make_pair('M', 1000));

    int number = 0;
    int lastInserted = INT_MAX;
    for (auto it : rm)
    {
        int current = romans.at(it);
        if (current > lastInserted)
        {
            number += current - 2 * lastInserted;
            lastInserted = current;
        }
        else
        {
            number += current;
            lastInserted = current;
        }
    }
    return number;
}

int main(int argc, char const *argv[])
{
    // freopen("_input.txt", "r", stdin);
    int t = 0;
    cin >> t;
    while (t--)
    {
        string r;
        cin >> r;
        cout << romanToInteger(r) << endl;
    }
    return 0;
}