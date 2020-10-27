#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

string removeDuplicated(string str)
{

    unordered_map<char, int> ump;
    string result = "";
    for (auto it : str)
    {
        ump[it]++;
        // mean character is repeating
        if (ump[it] > 1)
        {
            continue;
        }
        result += it;
    }

    return result;
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
        cout << removeDuplicated(s) << endl;
    }
    return 0;
}