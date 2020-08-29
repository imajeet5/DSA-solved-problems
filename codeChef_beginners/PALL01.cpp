//The Block Game
#include <bits/stdc++.h>
#define REP(i, a, b) for (i = a; i < b; i++)
//#define rep(i, n) REP(i, 0, n)

using namespace std;

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    while (n--)
    {
        int a, num;
        cin >> num;
        a = num;
        int pall = 0;
        while (a)
        {
            pall = pall * 10 + (a % 10);
            a = a / 10;
        }

        if (pall == num)
        {
            cout << "wins" << endl;
        }
        else
        {
            cout << "loses" << endl;
        }
    }
    return 0;
}