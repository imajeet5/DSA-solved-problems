//GCD and LCM
//if one of the numbers is zero, the greatest common divisor is the other number.

#include <bits/stdc++.h>
#define REP(i, a, n) for (i = a; i < n; i++)
//#define rep(i, n) REP(i, 0, n)

using namespace std;

typedef long long int ll;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("_input.txt", "r", stdin);
        freopen("_output.txt", "w", stdout);
    #endif
    int t = 0;
    cin >> t;
    while (t--)
    {
        ll n1, n2;
        cin >> n1 >> n2;
        cout << gcd(n1, n2) << " " << lcm(n1, n2) << endl;
    }

    return 0;
}