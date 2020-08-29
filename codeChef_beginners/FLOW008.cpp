//Helping Chef
#include <bits/stdc++.h>

using namespace std;

void output(int num)
{
    if (num < 10)
    {
        cout << "Thanks for helping Chef!" << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        output(a);
    }
    return 0;
}