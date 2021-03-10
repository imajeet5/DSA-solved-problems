#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

// not working currently

bool isPalindrome(string s)
{
    string rev = s;
    reverse(s.begin(), s.end());
    return rev == s;
}

int charForPalindrome(string s)
{
    int n = s.length() - 1;
    int ans = 0;
    for (int i = n; i > 0; i--)
    {
        string subst = s.substr(0, n + 1);
        if (isPalindrome(subst))
        {
            return ans;
        }
        ans++;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    freopen("_input.txt", "r", stdin);
    int t = 0;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << charForPalindrome(s) << endl;
    }
    return 0;
}

/*
3
abcd
aba
geeks
*/