#include <bits/stdc++.h>
#define rep(n) for (int i = 0; i < n; i++)
#define REP(i, n) for (i = 0; i < n; i++)
// #define rep(i, n) REP(i, 0, n)

using namespace std;

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    int oddNums = 0;
    int evenNums = 0;

    for (int i = 0; i < n; i++)
    {
        int num = 0;
        cin >> num;
        if (num % 2 == 0)
        {
            evenNums++;
        }
        else
        {
            oddNums++;
        }
    }
    if (evenNums > oddNums)
    {
        cout << "READY FOR BATTLE" << endl;
    }
    else
    {
        cout << "NOT READY" << endl;
    }

    return 0;
}