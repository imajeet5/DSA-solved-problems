//Chef And Operators
#include <bits/stdc++.h>

using namespace std;

char getOperator(int a, int b)
{
    if (a == b)
    {
        return '=';
    };
    if (a > b)
    {
        return '>';
    };
    if (a < b)
    {
        return '<';
    }
}

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        cout << getOperator(a, b) << endl;
    }
    return 0;
}