#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int my_atoi(string s)
{
    vector<int> num;
    int ans = 0;
    bool isNegative = false;
    if (s[0] == '-')
    {
        isNegative = true;
        s = s.substr(1, s.length());
    }
    for (auto it : s)
    {

        int n = it - '0';
        if (n >= 0 && n <= 9)
        {
            ans = ans * 10 + n;
        }
        else
        {
            return -1;
        }
    }

    if (isNegative)
    {
        ans *= -1;
    }

    return ans;
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
        cout << my_atoi(s) << endl;
    }
    return 0;
}