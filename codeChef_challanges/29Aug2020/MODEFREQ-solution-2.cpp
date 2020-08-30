#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
#define ld double
#define REP(i, x, n) for (ll i = x; i < n; i++)
#define SZ(v) (ll) v.size()
#define endl "\n"
#define ff first
#define ss second
#define setbit(x) __builtin_popcount(x)
#define prec(n) fixed << setprecision(n)
#define pb(n) push_back(n)
#define mp(a, b) make_pair(a, b)
#define clr(n) memset(n, 0, sizeof(n))
#define reset(n) memset(n, -1, sizeof(n))
#define ii pair<ll, ll>
#define vll vector<ll>

using namespace std;
const ll INF = 1e16;
const ll nxm = 10000 + 5;

void solve()
{

    ll n;

    cin >> n;

    ll a[n];

    REP(i, 0, n)
    cin >> a[i];

    vector<ll> fre(11, 0);

    vector<ll> fre2(nxm, 0);

    ll maxi = -1;

    REP(i, 0, n)
    {
        fre[a[i]]++;
    }

    REP(i, 0, 11)
    {
        if (fre[i] == 0)
            continue;

        fre2[fre[i]]++;

        maxi = max(maxi, fre2[fre[i]]);

        bool ok = 1;

        REP(i, 0, 1000)
        ok = 1;
    }

    REP(i, 0, nxm)
    {

        if (fre2[i] == maxi)
        {

            cout << i << endl;
            return;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    cin >> t;
    REP(i, 1, t + 1)
    {
        //    cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
